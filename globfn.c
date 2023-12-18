// global functions to be used in any file

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
    #include <time.h>
#endif

int clearscreen() {
    #ifdef _WIN32
        system("cls");  // Windows
        return 0;
    #elif defined(__linux__)
        system("clear");  // Linux
        return 0;
    #elif defined(__APPLE__)
        system("clear");  // MacOS
        return 0;
    #else
        #error "Unsupported platform"
        return 1;
    #endif
}

void sleepS(int seconds) {
    #ifdef _WIN32
        Sleep(seconds * 1000);
    #else
        sleep(seconds);
    #endif
}

void sleepMS(int milliseconds) {
    #ifdef _WIN32
        Sleep(milliseconds);
    #else
        struct timespec ts;
        ts.tv_sec = milliseconds / 1000;
        ts.tv_nsec = (milliseconds % 1000) * 1000000;
        nanosleep(&ts, NULL);
    #endif
}
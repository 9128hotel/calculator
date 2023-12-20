// global functions to be used in any file

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

#ifdef _WIN32
    #include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
    #include <time.h>   // for nanosleep
#else
    #include <unistd.h> // for usleep
#endif

void sleepMS(int milliseconds) {
    #ifdef _WIN32
        Sleep(milliseconds);
    #elif _POSIX_C_SOURCE >= 199309L
        struct timespec ts;
        ts.tv_sec = milliseconds / 1000;
        ts.tv_nsec = (milliseconds % 1000) * 1000000;
        nanosleep(&ts, NULL);
    #else
        if (milliseconds >= 1000)
          sleep(milliseconds / 1000);
        usleep((milliseconds % 1000) * 1000);
    #endif
}
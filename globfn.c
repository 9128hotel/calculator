// global functions to be used in any file

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
    #include <time.h>   // for nanosleep
#elif defined(__linux__)
    #include <unistd.h> // for usleep
#endif // this could do with an else case

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
    #elif _POSIX_C_SOURCE >= 199309L // old standard, shouldn't run
        struct timespec ts;
        ts.tv_sec = milliseconds / 1000;
        ts.tv_nsec = (milliseconds % 1000) * 1000000;
        nanosleep(&ts, NULL);
    #elif defined(__linux__)
        sleep(milliseconds / 1000);
    #endif
}
#include <time.h>
#include <stdlib.h>
#include "utils.h"

void wait(float seconds) {
    struct timespec ts;
    ts.tv_sec = (int)seconds;
    ts.tv_nsec = (seconds - (int)seconds) * 1e9;
    nanosleep(&ts, NULL);
}

void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
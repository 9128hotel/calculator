#include "globfn.h"
#include <stdio.h>

int main() {
    printf("This is before the delay.\n");
    sleepS(2);
    printf("This is after the delay.\n");
    sleepMS(500);
    printf("This is after another delay.\n");
    
    return 0;
}
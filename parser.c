#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* parse(char* command) {

    int len = strlen(command);
    
    // calculate memory required for parsed result
    int memlen = 0;
    for (int i = 0; i < len; i++) {
        if (command[i] >= '0' && command[i] <= '9') {
            memlen++;
        } else if (command[i] == '+' || command[i] == '-' || command[i] == '*' || command[i] == '/') {
            memlen += 3;
        }
    }

    char* res = (char*)malloc(sizeof(char) * (memlen + 1)); // add 1 for null terminator
    if (res == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int resPosition = 0;

    // parse input
    for (int i = 0; i < len; i++) {
        if (command[i] >= '0' && command[i] <= '9') {
            res[resPosition] = command[i];
            resPosition++;
        } else if (command[i] == '+' || command[i] == '-' || command[i] == '*' || command[i] == '/') {
            res[resPosition] = '\x1F';
            resPosition++;
            res[resPosition] = command[i];
            resPosition++;
            res[resPosition] = '\x1F';
            resPosition++;
        }
    }

    res[resPosition] = '\0'; // null-terminate result string

    return res;
}
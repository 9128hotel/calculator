#include <stdio.h>
#include <string.h>

char* parse(char* command) {
    printf("Print: %s\n", command);

    for (int i=0; i<strlen(command); i++) {
        printf("%c\n", command[i]);
    }

    return command;
}
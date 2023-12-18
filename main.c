#include "globfn.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    char* command = (char*)malloc(sizeof(char) * 101);

    if (command == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter sum (max 100 char): ");
    scanf("%100s", command);
    printf("Print: %s", command);
    free(command);

    return 0;
}
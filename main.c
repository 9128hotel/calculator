#include "globfn.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    char* raw = (char*)malloc(sizeof(char) * 101);

    if (raw == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter sum (max 100 char): ");
    scanf("%100s", raw);
    printf("Print: %s", raw);

    char* postparse = parse(raw);
    free(raw);

    return 0;
}
#include "globfn.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    char* raw = (char*)malloc(sizeof(char) * 101);

    if (raw == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter sum (max 100 char): ");
    scanf("%101[^\n]", raw); // don't use %s, it goes to a whitespace. %101[^\n] allows 100 characters and scans until a new line

    printf("Print: %s\n", raw);
    char* postparse = parse(raw);
    free(raw);
    free(postparse);

    return 0;
}
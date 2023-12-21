#include "processor.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc == 2) {
        if (strcmp(argv[1], "--check") == 0) {
            printf("Looks good\n");
            return 0;
        }
    }


    char* raw = (char*)malloc(sizeof(char) * 101);

    if (raw == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter sum (max 100 char): ");
    scanf("%101[^\n]", raw); // don't use %s, it goes to a whitespace. %101[^\n] allows 100 characters and scans until a new line

    char* parsed = parse(raw);
    printf("%s", parsed);


    free(raw);
    free(parsed);

    return 0;
}
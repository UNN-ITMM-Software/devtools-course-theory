// Copyright 2013 Ilia Udalov

#include <stdlib.h>
#include <stdio.h>

#include "../include/regex.h"

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("This is a simple handler for regexps and substrings.\n");
        printf("Please provide arguments in the following format:\n\n");
        printf("  $ %s <regexp> <substring> <text>\n\n", argv[0]);
        return 0;
    } else if (argc > 4) {
        printf("ERROR: Too much arguments!\n");
        return 0;
    }

    int is_match = match(argv[1], argv[3]);
    if (is_match) {
        printf("Regexp: match.\n");
    } else {
        printf("Regexp: does not match.\n");
    }

    int pos = find(argv[2], argv[3]);
    if (pos != -1) {
        printf("Substring: first pos is: %d.\n", pos);
    } else {
        printf("Substring: does not found.\n");
    }

    return 0;
}

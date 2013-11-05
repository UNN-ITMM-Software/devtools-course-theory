// Copyright 2013 Ilia Udalov

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "../include/regex.h"

#define BUF_SIZE 100

int main(int argc, char* argv[]) {
    FILE *inp;
    char buf[BUF_SIZE];
    std::string regex, substr, text;

    if ((inp = fopen(argv[1], "r")) == NULL) {
        printf("Input error\n");
        return 0;
    }

    while ((inp != NULL) && (fgets(buf, BUF_SIZE, inp))) {
        regex = buf;
        regex = regex.substr(0, regex.size()-1);
        if (!fgets(buf, BUF_SIZE, inp))
            exit(0);
        substr = buf;
        substr = substr.substr(0, substr.size()-1);
        if (!fgets(buf, BUF_SIZE, inp))
            exit(0);
        text = buf;
        text = text.substr(0, text.size()-1);

        printf("Text: %s\n", text.c_str());
        printf("Regex: %s; is match: %d\n", regex.c_str(), match(regex, text));
        printf("Find: %s; Substring position: %d\n",
            substr.c_str(), find(substr, text));
    }

    fclose(inp);
    return 0;
}

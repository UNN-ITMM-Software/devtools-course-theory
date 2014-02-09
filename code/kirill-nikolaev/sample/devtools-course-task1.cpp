// Copyright 2013 K.Nikolaev

#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <string>
#include "library/NumConverter.h"

#pragma pack(push, 1)
typedef struct {
    NumSystem numsys;
    char* number;
} Argument;
#pragma pack(push)

void Help(const char* appname);
char* ParseNumber(char* num, NumSystem numsys);
Argument ParseArgs(int argc, char** argv);

void Help(const char* appname) {
    printf("This is a number converter application.\n");
    printf("Please provide arguments in the following format:\n\n");
    printf("  $ %s <numsystem> <number>\n\n", appname);
    printf("Where <numsys> is one of 'bin', 'oct', 'dec' or 'hex', ");
    printf("and <number> is unsigned integer in selected notation.\n");
    return;
}

char* ParseNumber(char* num, NumSystem numsys) {
    std::string s(num);
    if (numsys == bin) {
        if (s.length() > 31)
            throw "Wrong number format";
        for (unsigned int i = 0; i < s.length(); i++) {
            if (s[i] < 48 || s[i] > 49)
                throw "Wrong number format";
        }
    } else if (numsys == oct) {
        if (s.length() > 10)
            throw "Wrong number format";
        for (unsigned int i = 0; i < s.length(); i++) {
            if (s[i] < 48 || s[i] > 55)
                throw "Wrong number format";
        }
    } else if (numsys == dec) {
        if (s.length() > 9)
            throw "Wrong number format";
        for (unsigned int i = 0; i < s.length(); i++) {
            if (s[i] < 48 || s[i] > 57)
                throw "Wrong number format";
        }
    } else if (numsys == hex) {
        if (s.length() > 7)
            throw "Wrong number format";
        for (unsigned int i = 0; i < s.length(); i++) {
            if (s[i] < 48 || (s[i] > 57 && s[i] < 97) ||
                s[i] > 102)
                throw "Wrong number format";
        }
    }
    return num;
}

Argument ParseArgs(int argc, char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        exit(0);
    } else if (argc != 3) {
        printf("Error: Should be 2 arguments.");
        Help(argv[0]);
        exit(1);
    }
    Argument arg;
    if (strcmp(argv[1], "bin") == 0) {
        arg.numsys = bin;
    } else if (strcmp(argv[1], "oct") == 0) {
        arg.numsys = oct;
    } else if (strcmp(argv[1], "dec") == 0) {
        arg.numsys = dec;
    } else if (strcmp(argv[1], "hex") == 0) {
        arg.numsys = hex;
    } else {
        printf("Error: Wrong name for a number system.\n");
        exit(2);
    }
    try {
        arg.number = ParseNumber(argv[2], arg.numsys);
    }
    catch(...) {
        printf("Error: Wrong number format.\n");
        exit(3);
    }
    return arg;
}


int main(int argc, char** argv) {
    Argument arg;
    arg = ParseArgs(argc, argv);
    NumConverter a(std::string(arg.number), arg.numsys);
    switch (arg.numsys) {
        case bin: {
            printf("%s in bin.\n", a.GetValue().c_str());
            printf("Is %s in hex.\n", a.ToHex().c_str());
            printf("Is %s in oct.\n", a.ToOctal().c_str());
            printf("Is %s in dec.\n", a.ToDecimal().c_str());
            break;
        }
        case oct: {
            printf("%s in oct.\n", a.GetValue().c_str());
            printf("Is %s in hex.\n", a.ToHex().c_str());
            printf("Is %s in dec.\n", a.ToDecimal().c_str());
            printf("Is %s in bin.\n", a.ToBinary().c_str());
            break;
        }
        case dec: {
            printf("%s in dec.\n", a.GetValue().c_str());
            printf("Is %s in hex.\n", a.ToHex().c_str());
            printf("Is %s in oct.\n", a.ToOctal().c_str());
            printf("Is %s in bin.\n", a.ToBinary().c_str());
            break;
        }
        case hex: {
            printf("%s in hex.\n", a.GetValue().c_str());
            printf("Is %s in oct.\n", a.ToOctal().c_str());
            printf("Is %s in dec.\n", a.ToDecimal().c_str());
            printf("Is %s in bin.\n", a.ToBinary().c_str());
            break;
        }
    }
    return 0;
}

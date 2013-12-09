/* Copyright 2013 Denis Sabanov */

#include <AreaConverter.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <cstdio>

#pragma pack(push, 1)
typedef struct {
    double value;
    AreaType curUnit;
    AreaType newUnit;
} Expression;
#pragma pack(pop)

void help(const char* appname);
int64_t parseInteger(const char* arg);
double parseDouble(const char* arg);
Expression parseArguments(int argc, char** argv);

void help(const char* appname) {
    printf("This is a area convertor application.\n\n");
    printf("Please provide arguments in the following format:\n\n");
    printf(" $ %s <value> <unit> <unit>\n\n", appname);
    printf("The list of area units: \n");
    printf("\n 0 - sKilometer,\n 1 - hectare,\n 2 - ar, \n 3 - acre");
    printf("\n 4 - sMeter \n 5 - sFoot \n");
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (!end[0]) {
        printf("%s is valid\n", arg);
    } else {
        printf("%s is invalid\n", arg);
        throw "wrong number format";
    }
    return value;
}

int64_t parseInteger(const char* arg) {
    char* end;
    int64_t value = strtol(arg, &end, 10);

    if (!end[0]) {
        printf("%s is valid\n", arg);
    } else {
        printf("%s is invalid\n", arg);
        throw "wrong format";
    }
    return value;
}

Expression parseArguments(int argc, char** argv) {
    if (argc == 1) {
        help(argv[0]);
        exit(0);
    } else if (argc != 4) {
        printf("ERROR: Should be 3 arguments.\n\n");
        help(argv[0]);
        exit(1);
        }

    Expression expression;
    try {
        expression.value = static_cast<double>(parseDouble(argv[1]));
        if (expression.value < 0) {
                printf("Wrong value! Value must be > 0");
                exit(2);
            }
        expression.curUnit = static_cast<AreaType>(parseInteger(argv[2]));
        expression.newUnit = static_cast<AreaType>(parseInteger(argv[3]));
        }
    catch(...) {
        printf("Wrong format!");
        exit(2);
        }
    return expression;
}

int main(int argc, char** argv) {
    Expression expr = parseArguments(argc, argv);
    printf("%lf %d to %d = ", expr.value,
        expr.curUnit, expr.newUnit);
    AreaConverter Converter(expr.value, expr.curUnit);
    printf("%lf", Converter.ConvertToNewType(expr.newUnit));
    return 0;
}

/* Copyright 2013 Dmitry Vodopyanov */

#include <LengthConvertor.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    double value;
    LengthUnit UnitInput;
    LengthUnit UnitOutput;
} Expression;
#pragma pack(pop)

void help(const char* appname);
double parseDouble(const char* arg);
int64_t parseInteger(const char* arg);
Expression parseArguments(int argc, char** argv);

void help(const char* appname) {
    printf("This is a length convertor application.\n\n");
    printf("You should provide arguments in the following format:\n\n");
    printf("  $ %s <value> <input unit> <output unit>\n\n", appname);
    printf("Where <value> is double number, ");
    printf("and both units are one of\n");
    printf("0 = Inch, 1 = Foot, 2 = Yard, 3 = Mile,\n");
    printf("4 = Meter, 5 = KMeter, 6 = CMeter.\n");
}

double parseDouble(const char* value) {
    char* end;
    double num = strtof(value, &end);

    if (!end[0]) {
        printf("%s is valid\n", value);
    } else {
        printf("%s is invalid\n", value);
        throw "wrong number format";
    }

    return num;
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
        expression.UnitInput = static_cast<LengthUnit>(parseInteger(argv[2]));
        expression.UnitOutput = static_cast<LengthUnit>(parseInteger(argv[3]));
    }
    catch(...) {
        printf("Wrong format!");
        exit(2);
    }

    return expression;
}

int main(int argc, char** argv) {
    Expression expr = parseArguments(argc, argv);
    LengthConvertor convertor;
    Length length;
    length.value = expr.value;
    length.UnitInput = expr.UnitInput;
    length.UnitOutput = expr.UnitOutput;
    Length result = convertor.Convert(length);
    printf("%lf %d to %d = ", length.value,
                              length.UnitInput, length.UnitOutput);
    printf("%lf", result.value);

    /* test only for me */
    length1 = {1.3, KMeter, Meter};
    Length result1 = convertor.Convert(length1);
    printf("res %lf", length1.value);
    return 0;
}

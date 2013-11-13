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
int64_t parseUnit(const char* arg);
Expression parseArguments(int argc, char** argv);

void help(const char* appname) {
    printf("This is a length convertor application.\n\n");
    printf("You should provide arguments in the following format:\n\n");
    printf("  $ %s <value> <input unit> <output unit>\n\n", appname);
    printf("Where <value> is double number, ");
    printf("and both units are one of\n");
    printf("Inch, Foot, Yard, Mile,\n");
    printf("Meter, KMeter, CMeter.\n");
}

double parseDouble(const char* value) {
    char* end;
    double num = strtod(value, &end);

    if (!end[0]) {
        printf("%s is valid\n", value);
    } else {
        printf("%s is invalid\n", value);
        throw "wrong number format";
    }

    return num;
}

int64_t parseUnit(const char* arg) {
    LengthUnit unit;
    if ((strcmp(arg, "inch") == 0) | (strcmp(arg, "in") == 0)) {
        unit = Inch;
        printf("%s is valid\n", arg);
    } else if ((strcmp(arg, "foot") == 0) | (strcmp(arg, "ft") == 0)) {
        unit = Foot;
        printf("%s is valid\n", arg);
    } else if ((strcmp(arg, "yard") == 0) | (strcmp(arg, "yd") == 0)) {
        unit = Yard;
        printf("%s is valid\n", arg);
    } else if ((strcmp(arg, "mile") == 0) | (strcmp(arg, "ml") == 0)) {
        unit = Mile;
        printf("%s is valid\n", arg);
    } else if ((strcmp(arg, "meter") == 0) | (strcmp(arg, "m") == 0)) {
        unit = Meter;
        printf("%s is valid\n", arg);
    } else if ((strcmp(arg, "kmeter") == 0) | (strcmp(arg, "km") == 0)) {
        unit = KMeter;
        printf("%s is valid\n", arg);
    } else if ((strcmp(arg, "cmeter") == 0) | (strcmp(arg, "cm") == 0)) {
        unit = CMeter;
        printf("%s is valid\n", arg);
    } else {
        printf("%s is invalid\n", arg);
        throw "wrong format";
    }

    return unit;
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
        expression.UnitInput = static_cast<LengthUnit>(parseUnit(argv[2]));
        expression.UnitOutput = static_cast<LengthUnit>(parseUnit(argv[3]));
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
    LengthUnit UnitOutput = expr.UnitOutput;
    printf("%lf %s to %s = ", length.value,
                              argv[2], argv[3]);
    length = convertor.Convert(length, UnitOutput);
    printf("%lf", length.value);
    return 0;
}

/* Copyright 2013 Ksenya Kochanova */
#include <TemperatureConverter.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <cstdio>

#pragma pack(push, 1)
typedef struct {
    double value;
    TemperatureUnit newunit;
    TemperatureUnit oldunit;
} Expression;
#pragma pack(pop)

void help(const char* appname);
int64_t parseInteger(const char* arg);
Expression parseArguments(int argc, char** argv);

void help(const char* appname) {
    printf("This is a temperature convertor application.\n\n");
    printf("Please provide arguments in the following format:\n\n");
    printf(" $ %s <value> <unit> <unit>\n\n", appname);
    printf("Unit of temperature: \n");
    printf("\n0 - Celsius,\n1 - kelvin,\n2 - Fahrenheit, \n3 - Newton \n\n");
}
int64_t parseInteger(const char* arg) {
    char* end;
    int64_t value = strtol(arg, &end, 10);

    if (!end[0]) {
        printf("%s is valid\n", arg);
    } else {
        printf("%s is invalid\n", arg);
        throw "wrong value format";
    }

    return value;
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
Expression parseArguments(int argc, char** argv) {
    if (argc == 1) {
        help(argv[0]);
        exit(0);
    } else if (argc != 4) {
        printf("ERROR: Should be 3 arguments: value, oldunit, newunit.\n\n");
        help(argv[0]);
        exit(1);
    }
    Expression expression;
    try {
         expression.value = static_cast<double>(parseDouble(argv[1]));
         expression.oldunit = static_cast<TemperatureUnit>(parseInteger
         (argv[2]));
         expression.newunit = static_cast<TemperatureUnit>(parseInteger
         (argv[3]));
    if ((expression.oldunit == 0) &&(expression.value < -273.15)) {
        printf("Wrong value format for Celsius!\n");
        exit(2);
    }
    if ((expression.oldunit == 1) &&(expression.value < 0)) {
        printf("Wrong value format for Kelvin!\n");
        exit(3);
    }
    if ((expression.oldunit == 2) &&(expression.value < -459.67)) {
        printf("Wrong value format for Fahrenheit!\n");
        exit(4);
    }
    if ((expression.oldunit == 3) &&(expression.value < -90.14)) {
        printf("Wrong value format for Newton!\n");
        exit(5);
    }
    if (expression.oldunit < 0 || expression.oldunit > 3) {
        printf("%s - Wrong unit!\n", argv[2]);
        exit(6);
    } else {
        printf("%s is valid unit\n", argv[2]);
    }
    if (expression.newunit < 0 || expression.newunit > 3) {
        printf("%s - Wrong unit!\n", argv[3]);
        exit(7);
    } else {
        printf("%s is valid unit\n", argv[3]);
    }
        }
    catch(...) {
        printf("Wrong format!");
        exit(8);
        }
    return expression;
}
int main(int argc, char** argv) {
    int flag = 1;
    Temperature temperature;
    TemperatureUnit newUnit;
    TemperatureConvertor convertor;
    Expression expr = parseArguments(argc, argv);
    temperature.value = expr.value;
    temperature.unit = expr.oldunit;
    newUnit = expr.newunit;
    Temperature inCelsius = convertor.ConvertToCelsius(flag, temperature);
    Temperature outTemperature = convertor.ConvertFromCelsius(flag, inCelsius,
        newUnit);
    printf("Input: %lf %d \n", temperature.value, temperature.unit);
    printf("Output: ? %d\n", newUnit);
    printf("Result: %lf\n", outTemperature.value);
    return 0;
}

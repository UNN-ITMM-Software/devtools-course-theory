/* Copyright 2013 Ksenya Kochanova */
#include <TemperatureConverter.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <cstdio>

#pragma pack(push, 1)
typedef struct {
    int value;
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
    printf("\n0 - Celsius,\n1 - kelvin,\n2 - Fahrenheit,\n 3 - Newton \n\n");
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
    expression.value = static_cast<int>(parseInteger(argv[1]));
    if ((expression.newunit == 0) &&(expression.value < -273.15)) {
        printf("Wrong value format for Celsius!\n");
        exit(2);
    }
    if ((expression.newunit == 1) &&(expression.value < 0)) {
        printf("Wrong value format for Kelvin!\n");
        exit(3);
    }
    if ((expression.newunit == 2) &&(expression.value < -459.67)) {
        printf("Wrong value format for Fahrenheit!\n");
        exit(4);
    }
    if ((expression.newunit == 3) &&(expression.value < -90.14)) {
        printf("Wrong value format for Newton!\n");
        exit(5);
    }
    expression.oldunit = static_cast<TemperatureUnit>(parseInteger(argv[2]));
    if ((strlen(argv[2]) != 1) ||
        (expression.oldunit < 0 || expression.oldunit > 3)) {
        printf("%s - Wrong unit!\n", argv[2]);
        exit(6);
    } else {
        printf("%s is valid unit\n", argv[2]);
    }
    expression.newunit = static_cast<TemperatureUnit>(parseInteger(argv[3]));
    if ((strlen(argv[3]) != 1) ||
        (expression.newunit < 0 || expression.newunit > 3)) {
        printf("%s - Wrong unit!\n", argv[3]);
        exit(7);
    } else {
        printf("%s is valid unit\n", argv[3]);
    }
        return expression;
}
int main(int argc, char** argv) {
    Expression expr = parseArguments(argc, argv);
    Temperature temperature;
    TemperatureConvertor convertor;
    temperature.value = expr.value;
    temperature.unit = expr.oldunit;
    TemperatureUnit newUnit = expr.newunit;
    Temperature inCelsius = convertor.ConvertToCelsius(temperature);
    Temperature outTemperature = convertor.ConvertFromCelsius(inCelsius,
newUnit);
    printf("Result: %lf\n", outTemperature.value);
    return 0;
}

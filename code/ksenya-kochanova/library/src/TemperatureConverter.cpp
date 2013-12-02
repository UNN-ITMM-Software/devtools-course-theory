/* Copyright 2013 Ksenya Kochanova */
#include "library/TempConv_application.h
#include "library/TemperatureConverter.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

TempConv::TempConv() : message_("") {}

void TempConv::help(const char* appname) {
    message_ = std::string("This is a temperature convertor application.\n\n")

              "Please provide arguments in the following format:\n\n"

              "  $ "  appname  " <value> <currentUnit> <newUnit>\n\n";
}

double parseInteger(const char* arg);
TemperatureUnit parseUnit(const char* arg);

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

TemperatureUnit parseUnit(const char* arg) {
     TemperatureUnit unit;
     if (strcmp(arg, "Celsius") == 0) {
       unit = Celsius;
       printf("%s is valid\n", arg);
     } else if (strcmp(arg, "Kelvin") == 0) {
       unit = Kelvin;
       printf("%s is valid\n", arg);
     } else if (strcmp(arg, "Fahrenheit") == 0) {
       unit = Fahrenheit;
       printf("%s is valid\n", arg);
     } else if (strcmp(arg, "Newton") == 0) {
       unit = Newton;
       printf("%s is valid\n", arg);
     } else {
         printf("%s is invalid\n", arg);
         throw "Wrong format";
     }
     return unit;
}

bool Calculator::parseArguments(int argc, const char** argv,
                                           Expression* expression) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        message_ = "ERROR: Should be 3 arguments.\n\n";
        help(argv[0]);
        return false;
    }

        try {
             expression.value = static_cast<double>(parseDouble(argv[1]));
             expression.oldunit = static_cast<TemperatureUnit>(parseUnit
             (argv[2]));
             expression.newunit = static_cast<TemperatureUnit>(parseUnit
             (argv[3]));
             }
        catch(...) {
            printf("Wrong format!");
            return false;
            }
    return true;
}

std::string TempConv::operator()(int argc, const char** argv) {
    Expression expr;
    bool returnCode = parseArguments(argc, argv, &expr);
    if (returnCode != true)
        return message_;
    TempConv tempconv;
    std::ostringstream stream;
    stream << "Result = ";
    stream << tempconv.Temperature Convert(expr.value, expr.oldUnit,
    expr.newUnit);
        break;
    message_ = stream.str();
    return message_;
}

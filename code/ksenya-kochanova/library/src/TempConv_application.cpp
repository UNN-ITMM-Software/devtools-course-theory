/* Copyright 2013 Ksenya Kochanova */

#include "library/TempConv_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "library/TemperatureConverter.h"

TempConvApp::TempConvApp() : message_("") {}

void TempConvApp::help(const char* appname) {
    message_ += std::string("This is a temperature convertor application.\n\n")
             + "Please provide arguments in the following format:\n\n"
             + " $ " + appname + " <value> <currentUnit> <newUnit>\n\n";
}

double parseDouble(const char* arg);
TemperatureUnit parseUnit(const char* arg);

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);
    if (!end[0]) {
    } else {
      throw std::string("Wrong data!");
    }
    return value;
}

TemperatureUnit parseUnit(const char* arg) {
     TemperatureUnit unit;
     if (strcmp(arg, "Celsius") == 0) {
       unit = Celsius;
     } else if (strcmp(arg, "Kelvin") == 0) {
       unit = Kelvin;
     } else if (strcmp(arg, "Fahrenheit") == 0) {
       unit = Fahrenheit;
     } else if (strcmp(arg, "Newton") == 0) {
       unit = Newton;
     } else {
       throw std::string("Wrong data!");
     }
     return unit;
}

bool TempConvApp::parseArguments(int argc, const char** argv,
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
         expression->value = static_cast<double>(parseDouble(argv[1]));
         expression->oldunit = static_cast<TemperatureUnit>(parseUnit
         (argv[2]));
         expression->newunit = static_cast<TemperatureUnit>(parseUnit
         (argv[3]));
    }
    catch(...) {
         message_ = "Wrong data!";
         return false;
    }
    return true;
}

std::string TempConvApp::operator()(int argc, const char** argv) {
    Expression expr;
    std::ostringstream stream;
    bool returnCode = parseArguments(argc, argv, &expr);
    if (returnCode != true) {
        return message_;
    }
    TemperatureConvertor tempconv;
    Temperature oldTemp, t;
    oldTemp.value = expr.value;
    oldTemp.unit = expr.oldunit;
    try {
        t = tempconv.Convert(oldTemp, expr.newunit);
        stream << "Result = ";
        stream << t.value;
    }
    catch(...) {
        stream << "Wrong data!";
    }
    message_ = stream.str();
    return message_;
}

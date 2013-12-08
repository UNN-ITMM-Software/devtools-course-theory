/* Copyright 2013 Denis Sabanov */

#include "library/AreaConverterApp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <string>
#include <sstream>

AreaConverterApp::AreaConverterApp() : message_("") {}

void AreaConverterApp::help(const char* appname) {
    message_ += std::string("This is a area convertor application.\n\n")
    +"Please provide arguments in the following format:\n\n"
    +"  $ " + appname + "  <value> <Current_Unit> <New_Unit>\n\n"
    + "<value> is double number, "
    +"The list of area units: \n"
    +"\n 0 - sKilometer,\n 1 - hectare,\n 2 - ar, \n 3 - acre \n"
    +"4 - sMeter \n 5 - sFoot \n";
}

double parseDouble(const char* arg);
int64_t parseInteger(const char* arg);
AreaType parseAreaUnit(const char* arg);

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw "wrong number format";
    }

    return value;
}

int64_t parseInteger(const char* arg) {
    char* end;
    int64_t value = strtol(arg, &end, 10);

    if (end[0]) {
        throw "wrong number format";
    }

    return value;
}

AreaType parseAreaUnit(const char* arg) {
    AreaType value;
    if (strcmp(arg, "sKilometer") == 0) {
      value = sKilometer;
    } else if (strcmp(arg, "hectare") == 0) {
      value = hectare;
    } else if (strcmp(arg, "ar") == 0) {
      value = ar;
    } else if (strcmp(arg, "acre") == 0) {
      value = acre;
    } else if (strcmp(arg, "sMeter") == 0) {
      value = sMeter;
    } else if (strcmp(arg, "sFoot") == 0) {
      value = sFoot;
    } else {
        throw "Wrong number format!";
    }

    return value;
}

bool AreaConverterApp::parseArguments(int argc, char** argv,
                                                Expression* expression) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        printf("ERROR: Should be 3 arguments.\n\n");
        help(argv[0]);
        return false;
    }

    try {
        expression->value = static_cast<double>(parseDouble(argv[1]));
        expression->curUnit = static_cast<AreaType>(parseAreaUnit(argv[2]));
        expression->newUnit = static_cast<AreaType>
                                                (parseAreaUnit(argv[3]));
    }
    catch(...) {
        message_ = "Wrong number format!\n";
        return false;
    }

    return true;
}

std::string AreaConverterApp::operator()(int argc,
                                                   char** argv) {
    Expression expr;

    bool returnCode = parseArguments(argc, argv, &expr);
    if (returnCode != true)
        return message_;

    AreaConverter Converter;
    AreaType newUnit;
    Converter.SetValue(expr.value);
    Converter.SetAreaType(expr.curUnit);
    newUnit = expr.newUnit;

    std::ostringstream stream;
    stream << "Result = ";

    stream << Converter.ConvertToNewType(newUnit);

    message_ = stream.str();

    return message_;
}

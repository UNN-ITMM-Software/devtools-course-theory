// Copyright 2013 Dmitry Vodopyanov

#include "library/LengthConvertorApp.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "library/LengthConvertor.h"

LengthConvertorApp::LengthConvertorApp() : message_("") {}

void LengthConvertorApp::help(const char* appname) {
    message_ += std::string("This is a length convertor application.\n\n")
             + "You should provide arguments in the following format:\n\n"
             + "  $ " + appname + " <value> <input unit> <output unit>\n\n"
             + "Where <value> is double number, "
             + "and both units are one of\n"
             + "Inch, Foot, Yard, Mile, Meter, KMeter, CMeter.\n";
}

double parseDouble(const char* value);
LengthUnit parseUnit(const char* arg);

double parseDouble(const char* value) {
    char* end;
    double num = strtod(value, &end);

    if (end[0]) {
        throw "Wrong number format";
    }

    return num;
}

LengthUnit parseUnit(const char* arg) {
    LengthUnit unit;
    if ((strcmp(arg, "inch") == 0) | (strcmp(arg, "in") == 0)) {
        unit = Inch;
    } else if ((strcmp(arg, "foot") == 0) | (strcmp(arg, "ft") == 0)) {
        unit = Foot;
    } else if ((strcmp(arg, "yard") == 0) | (strcmp(arg, "yd") == 0)) {
        unit = Yard;
    } else if ((strcmp(arg, "mile") == 0) | (strcmp(arg, "ml") == 0)) {
        unit = Mile;
    } else if ((strcmp(arg, "meter") == 0) | (strcmp(arg, "m") == 0)) {
        unit = Meter;
    } else if ((strcmp(arg, "kmeter") == 0) | (strcmp(arg, "km") == 0)) {
        unit = KMeter;
    } else if ((strcmp(arg, "cmeter") == 0) | (strcmp(arg, "cm") == 0)) {
        unit = CMeter;
    } else {
        throw "Wrong unit format";
    }

    return unit;
}

bool LengthConvertorApp::parseArguments(int argc, const char** argv,
                                        Expression* expression) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        printf("ERROR: Should be 3 arguments.");
        help(argv[0]);
        return false;
    }

    try {
        expression->value = static_cast<double>(parseDouble(argv[1]));
        expression->UnitInput = static_cast<LengthUnit>(parseUnit(argv[2]));
        expression->UnitOutput = static_cast<LengthUnit>(parseUnit(argv[3]));
    }
    catch(...) {
        message_ = "Wrong data format!\n";
        return false;
    }

    return true;
}

std::string LengthConvertorApp::operator()(int argc, const char** argv) {
    Expression expr;

    bool returnCode = parseArguments(argc, argv, &expr);
    if (returnCode != true)
        return message_;

    LengthConvertor convertor;
    Length length;
    length.value = expr.value;
    length.UnitInput = expr.UnitInput;
    LengthUnit UnitOutput = expr.UnitOutput;

    std::ostringstream stream;
    stream << "Result = ";

    stream << convertor.Convert(length, UnitOutput).value;

    message_ = stream.str();

    return message_;
}

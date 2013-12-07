/* Copyright 2013 Pavel Korotaev */

#include "library/weightconvertor_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "library/WeightConvertor.h"

WeightConvertorApplication::WeightConvertorApplication() : message_("") {}

void WeightConvertorApplication::help(const char* appname) {
    message_ += std::string("This is a weight convertor application.\n\n")
             + "Please provide arguments in the following format:\n\n"
             + "  $ " + appname + " <value> <input unit> <output unit>\n\n"
             + "Where <value> is double number, "
             + "and both units are one of\n"
             + "0 = Ounce, 1 = Pound, 2 = Stone, 3 = Grams,\n"
             + "4 = Kilograms, 5 = Hundredweight, 6 = Ton.\n";
}

double parseDouble(const char* arg);
int64_t parseInteger(const char* arg);
WeightUnit parseWeightUnit(const char* arg);

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

WeightUnit parseWeightUnit(const char* arg) {
    WeightUnit value;
    if (strcmp(arg, "Ounce") == 0) {
      value = Ounce;
    } else if (strcmp(arg, "Pound") == 0) {
      value = Pound;
    } else if (strcmp(arg, "Stone") == 0) {
      value = Stone;
    } else if (strcmp(arg, "Grams") == 0) {
      value = Grams;
    } else if (strcmp(arg, "Kilograms") == 0) {
      value = Kilograms;
    } else if (strcmp(arg, "Hundredweight") == 0) {
      value = Hundredweight;
    } else if (strcmp(arg, "Ton") == 0) {
      value = Ton;
    } else {
        throw "Wrong number format!";
    }

    return value;
}

bool WeightConvertorApplication::parseArguments(int argc, const char** argv,
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
        expression->unit = static_cast<WeightUnit>(parseWeightUnit(argv[2]));
        expression->UnitOutput = static_cast<WeightUnit>
                                                (parseWeightUnit(argv[3]));
    }
    catch(...) {
        message_ = "Wrong number format!\n";
        return false;
    }

    return true;
}

std::string WeightConvertorApplication::operator()(int argc,
                                                   const char** argv) {
    Expression expr;

    bool returnCode = parseArguments(argc, argv, &expr);
    if (returnCode != true)
        return message_;

    WeightConvertor Conv;
    Weight weight;
    WeightUnit UnitOutput;
    weight.value = expr.value;
    weight.unit = expr.unit;
    UnitOutput = expr.UnitOutput;

    std::ostringstream stream;
    stream << "Result = ";

    stream << Conv.ConvertTo(weight, UnitOutput).value;

    message_ = stream.str();

    return message_;
}

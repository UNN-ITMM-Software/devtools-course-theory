/* Copyright 2013 Vasiliy Kumaev */

#include "library/ÑurrencyConvertApplication.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "library/CurrencyConvert.h"

CurrencyConvertorApplication::CurrencyConvertorApplication() : message_("") {}

void CurrencyConvertorApplication::help(const char* appname) {
    message_ += std::string("This is a currency convertor application.\n\n")
             + "You should provide arguments in the following format:\n\n"
             + "  $ " + appname + " <value> <input unit> <output unit>\n\n"
             + "Where <value> is double number, "
             + "and both units are one of"
             + "\n - Dollar,\n - Euro,\n - Ruble,\n - Pound\n";
}

double parseDouble(const char* arg);
int64_t parseInteger(const char* arg);
Unit parseUnit(const char* arg);

double parseDouble(const char* value) {
    char* end;
    double number = static_cast<double>(strtod(value, &end));

    if (!end[0]) {
    } else {
        throw "Wrong format!";
    }

    return number;
}

int64_t parseInteger(const char* arg) {
    char* end;
    int64_t value = strtol(arg, &end, 10);

    if (!end[0]) {
    } else {
        throw "Wrong format!";
    }

    return value;
}

Unit parseUnit(const char* value) {
    Unit un;
    if (strcmp(value, "Ruble") == 0) {
      un = Ruble;
    } else if (strcmp(value, "Dollar") == 0) {
      un = Dollar;
    } else if (strcmp(value, "Euro") == 0) {
      un = Euro;
    } else if (strcmp(value, "Pound") == 0) {
      un = Pound;
    } else {
        throw "Wrong format!";
    }

    return un;
}

bool CurrencyConvertorApplication::parseArguments(int argc, const char** argv,
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
        expression->oldunit = static_cast<Unit>(parseUnit(argv[2]));
        expression->newunit = static_cast<Unit>(parseUnit(argv[3]));
    }
    catch(...) {
        message_ = "Wrong format!\n";
        return false;
    }
    return true;
}

std::string CurrencyConvertorApplication::operator()(int argc,
                                                     const char** argv) {
    Expression expr;
    std::ostringstream stream;

    bool returnCode = parseArguments(argc, argv, &expr);
    if (returnCode != true)
        return message_;

    CurrencyConvert convertor;
    Currency currency;
    Unit NewUnit;
    currency.value = expr.value;
    currency.unit = expr.oldunit;
    NewUnit = expr.newunit;

    stream << "Result = ";

    stream << convertor.Convert(currency, NewUnit).value;

    message_ = stream.str();

    return message_;
}

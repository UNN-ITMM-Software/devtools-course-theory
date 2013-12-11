// Copyright 2013 Kirill Kornyakov

#include "library/calc_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "library/simplecalc.h"

CalculatorApplication::CalculatorApplication() : message_("") {}

void CalculatorApplication::help(const char* appname) {
    message_ += std::string("This is a simple calculator application.\n\n")
             + "Please provide arguments in the following format:\n\n"
             + "  $ " + appname + " <argument1> <argument2> <operation>\n\n"
             + "Where both arguments are integer numbers, "
             + "and <operation> is one of '+' or '-'.\n";
}

int64_t parseInteger(const char* arg);
int64_t parseInteger(const char* arg) {
    char* end;
    int64_t value = strtol(arg, &end, 10);

    if (end[0]) {
        throw "Wrong number format";
    }

    return value;
}

bool CalculatorApplication::parseArguments(int argc, const char** argv,
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
        expression->arg1 = static_cast<int>(parseInteger(argv[1]));
        expression->arg2 = static_cast<int>(parseInteger(argv[2]));
    }
    catch(...) {
        message_ = "Wrong number format!\n";
        return false;
    }

    const char* op = argv[3];
    if ((strlen(op) != 1) || (*op != '+' && *op != '-')) {
        message_ = std::string(op) + " - Wrong operation!\n";
        return false;
    } else {
        expression->operation = *op;
    }

    return true;
}

std::string CalculatorApplication::operator()(int argc, const char** argv) {
    Expression expr;

    bool returnCode = parseArguments(argc, argv, &expr);
    if (returnCode != true)
        return message_;

    SimpleCalculator calc;

    std::ostringstream stream;
    stream << "Result = ";

    switch (expr.operation) {
     case '+':
        stream << calc.Add(expr.arg1, expr.arg2);
        break;
     case '-':
        stream << calc.Sub(expr.arg1, expr.arg2);
        break;
    }

    message_ = stream.str();

    return message_;
}

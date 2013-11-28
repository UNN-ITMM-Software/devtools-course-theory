// Copyright 2013 Kirill Kornyakov

#include "library/calc_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>

#include "library/simplecalc.h"

void help(const char* appname);
int64_t parseInteger(const char* arg);
Expression parseArguments(int argc, char** argv);

void CalculatorApplication::help(const char* appname) {
    message += std::string("This is a simple calculator application.\n\n")
            + "Please provide arguments in the following format:\n\n"
            + "  $ " + appname + " <argument1> <argument2> <operation>\n\n"
            + "Where both arguments are integer numbers, "
            + "and <operation> is one of '+' or '-'.\n";
}

int64_t parseInteger(const char* arg) {
    char* end;
    int64_t value = strtol(arg, &end, 10);

    if (!end[0]) {
        printf("%s is valid\n", arg);
    } else {
        printf("%s is invalid\n", arg);
        throw "wrong number format";
    }

    return value;
}

Expression CalculatorApplication::parseArguments(int argc, char** argv) {
    Expression expression;

    if (argc == 1) {
        help(argv[0]);
        return expression;
    } else if (argc != 4) {
        message = "ERROR: Should be 3 arguments.\n\n";
        help(argv[0]);
        return expression;
    }

    try {
        expression.arg1 = static_cast<int>(parseInteger(argv[1]));
        expression.arg2 = static_cast<int>(parseInteger(argv[2]));
    }
    catch(...) {
        message = "Wrong number format!\n";
        return expression;
    }

    expression.operation = *argv[3];
    if ((strlen(argv[3]) != 1) ||
        (expression.operation != '+' && expression.operation != '-')) {
        message = std::string(argv[3]) + " - Wrong operation!\n";
        return expression;
    } else {
        printf("%s is valid operation\n", argv[3]);
    }

    return expression;
}

CalculatorApplication::CalculatorApplication() : message("") {}

std::string CalculatorApplication::operator()(int argc, char** argv) {
    Expression expr = parseArguments(argc, argv);

    if (message != "")
        return message;

    SimpleCalculator calc;
    const int MAX_LEN = 256;
    char buff[MAX_LEN];

    switch (expr.operation) {
     case '+':
        snprintf(buff, MAX_LEN, "Result = %d\n",
                 calc.Add(expr.arg1, expr.arg2));
        break;
     case '-':
        snprintf(buff, MAX_LEN, "Result = %d\n",
                 calc.Sub(expr.arg1, expr.arg2));
        break;
    }

    return std::string(buff);
}

// Copyright 2013 Aleksey Nesmelov

#include "library/fractcalc_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "library/fractcalc.h"

FractionCalculatorApplication::FractionCalculatorApplication() : message("") {}

void FractionCalculatorApplication::help(const char* appname) {
    message += std::string("This is a fraction calculator application.\n\n")
             + "Please provide arguments in the following format:\n\n"
             + "  $ " + appname + " <argument1> <argument2> <argument3>"
             + " <argument4> <operation>\n\n"
             + "Where all arguments are :\n "
             +"<argument1> - numenator of first fraction\n "
             +"<argument2> - denominator of first fraction\n "
             +"<argument3> - numenator of second fraction\n "
             +"<argument4> - denominator of second fraction\n "
             + "and <operation> is one of '+' , '-' , '*' or '/'.\n";
}

int64_t parseInteger(const char* arg);
int64_t parseInteger(const char* arg) {
    char* end;
    int64_t value = strtol(arg, &end, 10);

    if (end[0]) {
        throw "wrong number format";
    }

    return value;
}

bool FractionCalculatorApplication::parseArguments(int argc, const char** argv,
                                           Expression* expression) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        message = "ERROR: Should be 5 arguments.\n\n";
        help(argv[0]);
        return false;
    }

    try {
        expression->arg1 = static_cast<int>(parseInteger(argv[1]));
        expression->arg2 = static_cast<int>(parseInteger(argv[2]));
        expression->arg3 = static_cast<int>(parseInteger(argv[3]));
        expression->arg4 = static_cast<int>(parseInteger(argv[4]));
    }
    catch(...) {
        message = "Wrong number format!\n";
        return false;
    }

    const char* operation = argv[5];
    if ((strlen(operation) != 1) || 
        (*operation != '+' && *operation != '-' &&
        *operation != '*' && *operation != '/')) {
        message = std::string(operation) + " - Wrong operation!\n";
        return false;
    } else {
        expression->operation = *operation;
    }

    return true;
}

std::string FractionCalculatorApplication::operator()(int argc, const char** argv) {
    Expression expr;
    

    bool returnCode = parseArguments(argc, argv, &expr);
    if (returnCode != true)
        return message;

    Fraction fract1(expr.arg1, 1);
    Fraction fract2(expr.arg3, 1);
    try {
    fract1.SetDenominator(expr.arg2);
    fract2.SetDenominator(expr.arg4);
    }
    catch(...) {
    message = "Wrong denominator!";
    return message;
    }
    Fraction result(0, 1);

    std::ostringstream stream;
    stream << "Result = ";

    switch (expr.operation) {
     case '+':
        result = Fraction::Add(fract1, fract2);
        stream << result.GetNumenator() + " / " +
        result.GetDenominator();
        break;
     case '-':
        result = Fraction::Subtract(fract1, fract2);
        stream << result.GetNumenator() + " / " +
        result.GetDenominator();
        break;
     case '*':
        result = Fraction::Multiply(fract1, fract2);
        stream << result.GetNumenator() + " / " +
        result.GetDenominator();
        break;
     case '/':
        try {
        result = Fraction::Divide(fract1, fract2);
        }
        catch(...) {
        message = "Wrong divisor!";
        return message;
        }
        stream << result.GetNumenator() + " / " +
        result.GetDenominator();
        break;
    }

    message = stream.str();

    return message;
}

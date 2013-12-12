/* Copyright 2013 Andrey Golodyaev */



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "library/complexcalc_application.h"
#include "library/complexcalc.h"

ComplexCalculatorApplication::ComplexCalculatorApplication() : message_("") {}

void ComplexCalculatorApplication::help(const char* appname) {
    message_ += std::string("This is a calculator of complex numbers.\n\n")
             + "Please provide arguments in the following format:\n\n"
             + "  $ " + appname + " <argument1> <argument2> <operation>\n\n"
             + "Where both arguments are complex numbers"
             + "Format of complex number:\n"
             + "1) a+b*i or a+i*b\n"
             + "2) b*i+a or i*b+a\n"
             + "Where a, b - real number; * can be absent\n"
             + "<operation> is one of '+', '-', '*' or '/'.\n";
}

bool ComplexCalculatorApplication::parseArguments(int argc, const char** argv,
                                                  Expression* expression) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
              message_ = "ERROR: Should be 3 arguments.\n\n";
              return false;
    }
    bool b1 = expression->arg1.Input(argv[1]);
    bool b2 = expression->arg2.Input(argv[2]);
    if (b1 == false || b2 == false) {
        message_ = "Wrong number format!\n";
        return false;
    }
    expression->operation = argv[3][0];
    if (strlen(argv[3]) > 1 || (expression->operation != '+' &&
        expression->operation != '-' &&
        expression->operation != '*' &&
        expression->operation != '/')) {
        message_ = "Wrong operation!\n";
        return false;
    }
    return true;
}

std::string ComplexCalculatorApplication::operator()(int argc,
                                                     const char** argv) {
    Expression expr;

    bool returnCode = parseArguments(argc, argv, &expr);
    if (returnCode != true)
        return message_;

    ComplexNumber num;

    std::ostringstream stream;

    char str[35]="";

    switch (expr.operation) {
     case '+' :
        num = ComplexNumber::Add(expr.arg1, expr.arg2);
        stream << "A+B = ";
        break;
     case '-' :
        num = ComplexNumber::Sub(expr.arg1, expr.arg2);
        stream << "A-B = ";
        break;
     case '*' :
        num = ComplexNumber::Mul(expr.arg1, expr.arg2);
        stream << "A*B = ";
        break;
     case '/' :
        try {
        num = ComplexNumber::Div(expr.arg1, expr.arg2);
        }
        catch(...) {
        message_ = "division by zero";
        return message_;
        }
        stream << "A/B = ";
        break;
    }

    num.Output(str);
    stream << str;
    message_ = stream.str();


    return message_;
}


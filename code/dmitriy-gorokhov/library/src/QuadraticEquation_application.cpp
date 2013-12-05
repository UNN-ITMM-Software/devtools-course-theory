/* Copyright 2013 Dmitriy Gorokhov */

#include "library/QuadraticEquation_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>

#include "library/QuadraticEquation.h"

QuadraticEquationApplication::QuadraticEquationApplication() : message("") {}

void QuadraticEquationApplication::help(const char* appname) {
    message += std::string("This is a quadratic equation application.\n\n")
       + "Please provide arguments in the following format:\n\n"
       + "  $ " + appname + " <coefficient1> <coefficient2> <coefficient3>\n\n"
       + "Where all coefficients are real numbers.\n";
}

double parseDouble(const char* arg) {
    char* end;
    double value = static_cast<double>(strtod(arg, &end));

    if (end[0]) {
        throw "Wrong number format!";
    }

    return value;
}

bool QuadraticEquationApplication::parseArguments(int argc,
                                                  const char** argv,
                                                  Expression* expr) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        message = "ERROR: Should be 3 coefficients!\n\n";
        help(argv[0]);
        return false;
    }

    try {
        expr->a = static_cast<double>(parseDouble(argv[1]));
        expr->b = static_cast<double>(parseDouble(argv[2]));
        expr->c = static_cast<double>(parseDouble(argv[3]));
    }
    catch(...) {
        message = "Wrong coefficients format!\n";
        return false;
    }

    if (expr->a >= -EPS && expr->a <= EPS) {
        message = "First coefficient must be non-zero!\n";
        return false;
    }

    return true;
}

std::string QuadraticEquationApplication::operator()(int argc,
                                                     const char** argv) {
    Expression expression;

    bool parseCode = parseArguments(argc, argv, &expression);
    if (parseCode != true)
        return message;

    std::ostringstream stream;
    stream << "Result = ";

    QuadraticEquation quadEq(expression.a, expression.b, expression.c);
    double r1, r2;
    int returnCode;
    returnCode = quadEq.Solve(&r1, &r2);
    if (returnCode == NOREALROOT) {
        stream << "No real roots\n";
    } else {
        stream << "Root1 = ";
        stream << r1;
        stream << ", Root2 = ";
        stream << r2;
    }

    message = stream.str();

    return message;
}

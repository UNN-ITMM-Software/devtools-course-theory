/* Copyright 2013 Dmitriy Gorokhov */
#include <QuadraticEquation.h>
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
typedef struct {
    double a;
    double b;
    double c;
} Expression;
#pragma pack(pop)

void help(const char* appname);
double parseDouble(const char* arg);
Expression parseArguments(int argc, char** argv);

void help(const char* appname) {
    printf("This is a quadratic equation application.\n\n");
    printf("Please provide arguments in the following format:\n\n");
    printf("  $ %s <coefficient1> <coefficient2> <coefficient3>\n\n", appname);
    printf("Where all coefficients are real numbers.");
}

double parseDouble(const char* arg) {
    char* end;
    double value = static_cast<double>(strtod(arg, &end));

    if (!end[0]) {
        printf("%s is valid\n", arg);
    } else {
        printf("%s is invalid\n", arg);
        throw "wrong number format";
    }

    return value;
}

Expression parseArguments(int argc, char** argv) {
    if (argc == 1) {
        help(argv[0]);
        exit(0);
    } else if (argc != 4) {
        printf("ERROR: Should be 3 coefficients!\n\n");
        help(argv[0]);
        exit(1);
    }

    Expression expression;
    try {
        expression.a = static_cast<double>(parseDouble(argv[1]));
        expression.b = static_cast<double>(parseDouble(argv[2]));
        expression.c = static_cast<double>(parseDouble(argv[3]));
    }
    catch(...) {
        printf("Wrong coefficients format!\n");
        exit(2);
    }

    if (expression.a >= -EPS && expression.a <= EPS) {
        printf("First coefficient must be non-zero!\n");
    }

    return expression;
}

int main(int argc, char** argv) {
    Expression expr = parseArguments(argc, argv);

    QuadraticEquation Sample(expr.a, expr.b, expr.c);
    double r1, r2;
    int returnCode;
    returnCode = Sample.Solve(&r1, &r2);
    if (returnCode == NOREALROOT) {
        printf("No real roots\n");
    } else {
        printf("Root1 = %.3f, Root2 = %.3f\n", r1, r2);
    }

    return 0;
}

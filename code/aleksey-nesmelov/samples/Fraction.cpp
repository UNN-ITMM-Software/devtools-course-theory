/* Copyright 2013 Nesmelov Aleksey */
#include <fractcalc.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    int arg1;
    int arg2;
    int arg3;
    int arg4;
    char operation;
} Expression;
#pragma pack(pop)

void help(const char* appname);
int64_t parseInteger(const char* arg);
Expression parseArguments(int argc, char** argv);

void help(const char* appname) {
    printf("This is a fraction calculator application.\n\n");
    printf("Please provide arguments in the following format:\n\n");
    printf("  $ %s <argument1> <argument2> <argument3>", appname);
    printf(" <argument4> <operation>\n\n");
    printf("Where all arguments are :\n ");
    printf("<argument1> - numenator of first fraction\n ");
    printf("<argument2> - denominator of first fraction\n ");
    printf("<argument3> - numenator of second fraction\n ");
    printf("<argument4> - denominator of second fraction\n ");
    printf("and <operation> is one of '+' , '-' , '*' or '/'.\n");
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

Expression parseArguments(int argc, char** argv) {
    if (argc == 1) {
        help(argv[0]);
        exit(0);
    } else if (argc != 6) {
        printf("ERROR: Should be 5 arguments.\n\n");
        help(argv[0]);
        exit(1);
    }
    Expression expression;
    try {
        expression.arg1 = static_cast<int>(parseInteger(argv[1]));
        expression.arg2 = static_cast<int>(parseInteger(argv[2]));
        expression.arg3 = static_cast<int>(parseInteger(argv[3]));
        expression.arg4 = static_cast<int>(parseInteger(argv[4]));
    }
    catch(...) {
        printf("Wrong number format!\n");
        exit(2);
    }
    expression.operation = *argv[5];
    if ((strlen(argv[5]) != 1) ||
        (expression.operation != '+' && expression.operation != '-' &&
        expression.operation != '*' && expression.operation != '/')) {
        printf("%s - Wrong operation!\n", argv[5]);
        exit(5);
    } else {
        printf("%s is valid operation\n", argv[5]);
    }
    return expression;
}

int main(int argc, char** argv) {
    Expression expr = parseArguments(argc, argv);
    Fraction fract1(expr.arg1, 1);
    Fraction fract2(expr.arg3, 1);
    try {
    fract1.SetDenominator(expr.arg2);
    fract2.SetDenominator(expr.arg4);
    }
    catch(...) {
    printf("Wrong denominator!");
    exit(2);
    }
    Fraction result(0, 1);

    switch (expr.operation) {
     case '+':
        result = Fraction::Add(fract1, fract2);
        printf("Result = %d / %d\n", result.GetNumenator(),
        result.GetDenominator());
        break;
     case '-':
        result = Fraction::Subtract(fract1, fract2);
        printf("Result = %d / %d\n", result.GetNumenator(),
        result.GetDenominator());
        break;
     case '*':
        result = Fraction::Multiply(fract1, fract2);
        printf("Result = %d / %d\n", result.GetNumenator(),
        result.GetDenominator());
        break;
     case '/':
        try {
        result = Fraction::Divide(fract1, fract2);
        }
        catch(...) {
        printf("Wrong divisor!");
        exit(2);
        }
        printf("Result = %d / %d\n", result.GetNumenator(),
        result.GetDenominator());
        break;
    }

    return 0;
}


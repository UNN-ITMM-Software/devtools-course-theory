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
    printf("Where all arguments are integer numbers, ");
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
    if (expression.arg2 == 0) {
         printf("%s Denominator cannot be zero\n", argv[2]);
    if (expression.arg4 == 0) {
         printf("%s Denominator cannot be zero\n", argv[4]);
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
    Fraction fract1(expr.arg1, expr.arg2);
    Fraction fract2(expr.arg3, expr.arg4);
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
        result = Fraction::Divide(fract1, fract2);
        printf("Result = %d / %d\n", result.GetNumenator(),
        result.GetDenominator());
        break;
    }

    return 0;
}


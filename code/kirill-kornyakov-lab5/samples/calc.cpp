// Copyright 2013 Kirill Kornyakov

#include <simplecalc.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    int arg1;
    int arg2;
    char operation;
} Expression;
#pragma pack(pop)

void help(const char* appname);
int64_t parseInteger(const char* arg);
Expression parseArguments(int argc, char** argv);

void help(const char* appname) {
    printf("This is a simple calculator application.\n\n");
    printf("Please provide arguments in the following format:\n\n");
    printf("  $ %s <argument1> <argument2> <operation>\n\n", appname);
    printf("Where both arguments are integer numbers, ");
    printf("and <operation> is one of '+' or '-'.\n");
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
    } else if (argc != 4) {
        printf("ERROR: Should be 3 arguments.\n\n");
        help(argv[0]);
        exit(1);
    }

    Expression expression;
    try {
        expression.arg1 = static_cast<int>(parseInteger(argv[1]));
        expression.arg2 = static_cast<int>(parseInteger(argv[2]));
    }
    catch(...) {
        printf("Wrong number format!\n");
        exit(2);
    }

    expression.operation = *argv[3];
    if ((strlen(argv[3]) != 1) ||
        (expression.operation != '+' && expression.operation != '-')) {
        printf("%s - Wrong operation!\n", argv[3]);
        exit(3);
    } else {
        printf("%s is valid operation\n", argv[3]);
    }

    return expression;
}

int main(int argc, char** argv) {
    Expression expr = parseArguments(argc, argv);
    SimpleCalculator calc;

    switch (expr.operation) {
     case '+':
        printf("Result = %d\n", calc.Add(expr.arg1, expr.arg2));
        break;
     case '-':
        printf("Result = %d\n", calc.Sub(expr.arg1, expr.arg2));
        break;
    }

    return 0;
}

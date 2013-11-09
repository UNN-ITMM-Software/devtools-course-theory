/* Copyright 2013 Andrey Golodyaev */
#include <complexcalc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct Exp {
    ComplexCalculator arg1;
    ComplexCalculator arg2;
    char operation;
    Exp(): arg1(), arg2(), operation('+') {
    }
} Expression;
#pragma pack(pop)

void help(const char* appname);
Expression parseArguments(int argc, char** argv);

void help(const char* appname) {
    printf("This is a calculator of complex numbers.\n\n");
    printf("Please provide arguments in the following format:\n\n");
    printf("  $ %s <argument1> <argument2> <operation>\n\n", appname);
    printf("Where both arguments are complex numbers");
    printf("Format of complex number:\n");
    printf("1) a+b*i or a+i*b\n");
    printf("2) b*i+a or i*b+a\n");
    printf("Where a, b - real number; * can be absent\n");
    printf("<operation> is one of '+', '-', '*' or '/'.\n");
}

Expression parseArguments(int argc, char** argv) {
    if (argc == 1) {
        help(argv[0]);
        exit(0);
    } else if (argc != 4) {
              printf("ERROR: Should be 3 arguments.\n\n");
              exit(1);
    }
    Expression expression;
    expression.arg1.Input(argv[1]);
    expression.arg2.Input(argv[2]);
    expression.operation = argv[3][0];
    if (strlen(argv[3]) > 1 || (expression.operation != '+' &&
        expression.operation != '-' &&
        expression.operation != '*' &&
        expression.operation != '/')) {
        printf("Wrong operation!\n");
        exit(3);
    }
    return expression;
}

int main(int argc, char** argv) {
    Expression expr = parseArguments(argc, argv);
    ComplexCalculator a;
    ComplexCalculator b;
    a = expr.arg1;
    b = expr.arg2;
    ComplexCalculator c;
    char str[35]="";

    switch (expr.operation) {
     case '+' :
        c = ComplexCalculator::Add(a, b);
        c.Output(str);
        printf("A+B = %s\n", str);
        break;
     case '-' :
        c = ComplexCalculator::Sub(a, b);
        c.Output(str);
        printf("A-B = %s\n", str);
        break;
     case '*' :
        c = ComplexCalculator::Multi(a, b);
        c.Output(str);
        printf("A*B = %s\n", str);
        break;
     case '/' :
        c = ComplexCalculator::Div(a, b);
        c.Output(str);
        printf("A/B = %s\n", str);
        break;
    }
    return 0;
}

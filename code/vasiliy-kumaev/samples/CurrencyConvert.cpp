/* Copyright 2013 Vasiliy Kumaev */

#include <CurrencyConvert.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    double value;
    Unit oldunit;
    Unit newunit;
} Expression;
#pragma pack(pop)

void help(const char* appname);
double parseDouble(const char* arg);
int64_t parseInteger(const char* arg);
Expression parseArguments(int argc, char** argv);

void help(const char* appname) {
    printf("This is a currency convertor application.\n\n");
    printf("You should provide arguments in the following format:\n\n");
    printf("  $ %s <value> <oldunit> <newunit>\n\n", appname);
    printf("Where <value> is double number, ");
    printf("and both units are one of");
    printf("0 = Dollar,\n 1 = Euro,\n 2 = Ruble,\n 3 = Pound\n");
}

double parseDouble(const char* value) {
    char* end;
    double number = static_cast<double>(strtod(value, &end));

    if (!end[0]) {
        printf("%s is valid\n", value);
    } else {
        printf("%s is invalid\n", value);
        throw "Wrong format";
    }

    return number;
}

int64_t parseInteger(const char* arg) {
    char* end;
    int64_t value = strtol(arg, &end, 10);

    if (!end[0]) {
        printf("%s is valid\n", arg);
    } else {
        printf("%s is invalid\n", arg);
        throw "Wrong format";
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
        expression.value = static_cast<double>(parseDouble(argv[1]));
        expression.oldunit = static_cast<Unit>(parseInteger(argv[2]));
        expression.newunit = static_cast<Unit>(parseInteger(argv[3]));
    }
    catch(...) {
        printf("Wrong format!\n");
        exit(4);
    }

    return expression;
}

int main(int argc, char** argv) {
    Expression expr = parseArguments(argc, argv);
    CurrencyConvert convertor;
    Currency currency;

    currency.value = expr.value;
    currency.oldunit = expr.oldunit;
    currency.newunit = expr.newunit;
    currency = convertor.Convert(currency);
    printf("Result = %.3lf", currency.value);

    return 0;
}

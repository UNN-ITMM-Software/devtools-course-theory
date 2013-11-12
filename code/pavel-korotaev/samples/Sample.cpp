/* Copyright 2013 Pavel Korotaev */

#include <WeightConvertor.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    double value;
    WeightUnit unit;
    WeightUnit UnitOutput;
} Expression;
#pragma pack(pop)

void help(const char* appname);
double parseDouble(const char* arg);
int64_t parseInteger(const char* arg);
WeightUnit parseWeightUnit(const char* arg);
Expression parseArguments(int argc, char** argv);

void help(const char* appname) {
    printf("This is a weight convertor application.\n\n");
    printf("Please provide arguments in the following format:\n\n");
    printf("  $ %s <value> <input unit> <output unit>\n\n", appname);
    printf("Where <value> is double number, ");
    printf("and both units are one of\n");
    printf("0 = Ounce, 1 = Pound, 2 = Stone, 3 = Grams,\n");
    printf("4 = Kilograms, 5 = Hundredweight, 6 = Ton.\n");
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (!end[0]) {
        printf("%s is valid\n", arg);
    } else {
        printf("%s is invalid\n", arg);
        throw "wrong number format";
    }

    return value;
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

WeightUnit parseWeightUnit(const char* arg) {
    WeightUnit value;
    if (strcmp(arg, "Ounce") == 0) {
      value = Ounce;
      printf("%s is valid\n", arg);
    } else if (strcmp(arg, "Pound") == 0) {
      value = Pound;
      printf("%s is valid\n", arg);
    } else if (strcmp(arg, "Stone") == 0) {
      value = Stone;
      printf("%s is valid\n", arg);
    } else if (strcmp(arg, "Grams") == 0) {
      value = Grams;
      printf("%s is valid\n", arg);
    } else if (strcmp(arg, "Kilograms") == 0) {
      value = Kilograms;
      printf("%s is valid\n", arg);
    } else if (strcmp(arg, "Hundredweight") == 0) {
      value = Hundredweight;
      printf("%s is valid\n", arg);
    } else if (strcmp(arg, "Ton") == 0) {
      value = Ton;
      printf("%s is valid\n", arg);
    } else {
        printf("%s is invalid\n", arg);
        throw "Wrong number format!";
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
        expression.unit = static_cast<WeightUnit>(parseWeightUnit(argv[2]));
        expression.UnitOutput = static_cast<WeightUnit>
                                                (parseWeightUnit(argv[3]));
    }
    catch(...) {
        printf("Wrong number format!\n");
        exit(2);
    }

    return expression;
}

int main(int argc, char** argv) {
    Expression expr = parseArguments(argc, argv);
    WeightConvertor Conv;
    Weight weight;
    WeightUnit UnitOutput;
    weight.value = expr.value;
    weight.unit = expr.unit;
    UnitOutput = expr.UnitOutput;
    printf("%lf %d to %d = ", weight.value, weight.unit, UnitOutput);
    weight = Conv.ConvertTo(weight, UnitOutput);
    printf("%lf", weight.value);
    return 0;
}

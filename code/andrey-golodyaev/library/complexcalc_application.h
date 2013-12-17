/* Copyright 2013 Andrey Golodyaev */

#ifndef CODE_ANDREY_GOLODYAEV_LIBRARY_COMPLEXCALC_APPLICATION_H_
#define CODE_ANDREY_GOLODYAEV_LIBRARY_COMPLEXCALC_APPLICATION_H_

#include <library/complexcalc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#pragma pack(push, 1)
typedef struct Exp {
    ComplexNumber arg1;
    ComplexNumber arg2;
    char operation;
    Exp(): arg1(), arg2(), operation('+') {
    }
} Expression;
#pragma pack(pop)

class ComplexCalculatorApplication {
 public:
    ComplexCalculatorApplication();

    std::string operator()(int argc, const char** argv);

 private:
    std::string message_;

    void help(const char* appname);
    bool parseArguments(int argc, const char** argv, Expression* expr);
};

#endif  // CODE_ANDREY_GOLODYAEV_LIBRARY_COMPLEXCALC_APPLICATION_H_

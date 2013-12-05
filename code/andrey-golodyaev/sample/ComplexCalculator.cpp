/* Copyright 2013 Andrey Golodyaev */

#include <library/complexcalc_application.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    ComplexCalculatorApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

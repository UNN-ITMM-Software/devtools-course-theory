/* Copyright 2013 Dmitriy Gorokhov */

#include "library/QuadraticEquationApplication.h"

#include <stdio.h>
#include <string>

int main(int argc, const char** argv) {
    QuadraticEquationApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

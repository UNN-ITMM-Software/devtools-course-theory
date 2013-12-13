/* Copyright 2013 Dmitriy Gorokhov */

#include <stdio.h>
#include <string>

#include "library/QuadraticEquationApplication.h"

int main(int argc, const char** argv) {
    QuadraticEquationApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

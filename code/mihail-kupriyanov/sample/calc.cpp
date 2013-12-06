// Copyright 2013 Michail Kupriyanov

#include "library/calc_application.h"

#include <stdio.h>
#include <string>

int main(int argc, const char** argv) {
    MathQuanCalcApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

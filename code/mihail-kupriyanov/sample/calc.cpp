// Copyright 2013 Michail Kupriyanov

#include <stdio.h>
#include <string>

#include "library/mathquancalc_application.h"

int main(int argc, const char** argv) {
    MathQuanCalcApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

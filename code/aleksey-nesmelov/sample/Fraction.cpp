// Copyright 2013 Aleksey Nesmelov

#include <stdio.h>
#include <string>

#include "library/fractcalc_application.h"

int main(int argc, const char** argv) {
    FractionCalculatorApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

// Copyright 2013 Aleksey Nesmelov

#include "library/fractcalc_application.h"

#include <stdio.h>
#include <string>

int main(int argc, const char** argv) {
    FractionCalculatorApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

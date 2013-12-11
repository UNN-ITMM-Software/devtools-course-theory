// Copyright 2013 Kirill Kornyakov

#include "library/calc_application.h"

#include <stdio.h>
#include <string>

int main(int argc, const char** argv) {
    CalculatorApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

/* Copyright 2013 Ksenya Kochanova */

#include <stdio.h>
#include <string>
#include "library/TempConvApp.h"

int main(int argc, const char** argv) {
    TempConvApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

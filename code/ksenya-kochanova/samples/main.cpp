/* Copyright 2013 Ksenya Kochanova */

#include "library/TempConv_application.h"
#include <string>
#include <stdio.h>

int main(int argc, const char** argv) {
    TempConv app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

/* Copyright 2013 Alexandr Smirnov */

#include "library/sort_application.h"

#include <stdio.h>
#include <string>

int main(int argc, const char** argv) {
    SorterApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
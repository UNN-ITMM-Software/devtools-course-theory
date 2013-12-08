/* Copyright 2013 Denis Sabanov */

#include <stdio.h>
#include <string>
#include "library/AreaConverterApp.h"

int main(int argc, char** argv) {
    AreaConverterApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return 0;
}

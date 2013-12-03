/* Copyright 2013 Dmitry Vodopyanov */

#include "library/LengthConvertorApp.h"

#include <stdio.h>
#include <string>

int main(int argc, char** argv) {
    LengthConvertorApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

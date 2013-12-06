/* Copyright 2013 Dmitry Vodopyanov */

#include <stdio.h>
#include <string>
#include "library/LengthConvertorApp.h"

int main(int argc, char** argv) {
    LengthConvertorApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

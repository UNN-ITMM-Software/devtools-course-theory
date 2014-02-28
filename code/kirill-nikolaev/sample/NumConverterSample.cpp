// Copyright 2013 K.Nikolaev

#include <stdio.h>
#include <string>

#include "library/NumConverter_application.h"

int main(int argc, const char** argv) {
    NumConverterApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

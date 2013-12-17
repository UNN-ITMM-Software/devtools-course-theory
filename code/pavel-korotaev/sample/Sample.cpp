/* Copyright 2013 Pavel Korotaev */

#include <stdio.h>
#include <string>
#include "library/weightconvertor_application.h"

int main(int argc, const char** argv) {
    WeightConvertorApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

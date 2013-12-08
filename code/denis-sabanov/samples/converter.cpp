/* Copyright 2013 Denis Sabanov */

#include "library/AreaConverterApp.h"
#include <string>

int main(int argc, char** argv) {
    AreaConverterApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return 0;
}

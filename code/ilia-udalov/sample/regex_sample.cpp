// Copyright 2013 Ilia Udalov

#include "library/regex_application.h"

#include <stdio.h>
#include <string>

int main(int argc, const char** argv) {
    RegexApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

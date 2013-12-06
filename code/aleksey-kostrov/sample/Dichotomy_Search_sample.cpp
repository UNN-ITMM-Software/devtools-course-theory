/* Copyright 2013 Aleksey Kostrov */


#include "library/Dichotomy_Search_application.h"

#include <stdio.h>
#include <string>

int main(int argc, const char** argv) {
    DichotomySearchApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
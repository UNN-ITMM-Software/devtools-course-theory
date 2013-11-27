/* Copyright 2013 Anna Zhbanova */

#include "library/Triangle_application.h"

#include <stdio.h>
#include <string>

int main(int argc, char** argv) {
    TriangleApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

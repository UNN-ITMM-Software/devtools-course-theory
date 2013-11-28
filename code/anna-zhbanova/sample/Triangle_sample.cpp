/* Copyright 2013 Anna Zhbanova */

#include "library/Triangle_application.hpp"

#include <stdio.h>
#include <string>

int main(int argc, const char** argv) {
    TriangleApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

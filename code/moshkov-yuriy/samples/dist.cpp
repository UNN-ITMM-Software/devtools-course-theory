/* Copyright 2013 Moshkov Yuriy */
#include <stdio.h>
#include <string>

#include "library/DistApplication.h"

int main(int argc, char* argv[]) {
    DistApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

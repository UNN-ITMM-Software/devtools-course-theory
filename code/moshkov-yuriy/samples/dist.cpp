/* Copyright 2013 Moshkov Yuriy */
#include "library/DistApplication.h"
#include <string>

int main(int argc, char* argv[]) {
    DistApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

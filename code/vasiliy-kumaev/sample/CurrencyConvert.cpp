/* Copyright 2013 Vasiliy Kumaev */

#include <stdio.h>
#include <string>
#include "library/currencyconvert_application.h"

int main(int argc, const char** argv) {
    CurrencyConvertorApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

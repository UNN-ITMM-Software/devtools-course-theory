/* Copyright 2013 Vasiliy Kumaev */

#ifndef CODE_VASILIY_KUMAEV_LIBRARY_CURRENCYCONVERT_APPLICATION_H_
#define CODE_VASILIY_KUMAEV_LIBRARY_CURRENCYCONVERT_APPLICATION_H_

#include <string>
#include "library/CurrencyConvert.h"

#pragma pack(push, 1)
typedef struct {
    double value;
    Unit oldunit;
    Unit newunit;
} Expression;
#pragma pack(pop)

class CurrencyConvertorApplication {
 public:
    CurrencyConvertorApplication();

    std::string operator()(int argc, const char** argv);

 private:
    std::string message_;

    void help(const char* appname);
    bool parseArguments(int argc, const char** argv, Expression* expr);
};

#endif  // CODE_VASILIY_KUMAEV_LIBRARY_CURRENCYCONVERT_APPLICATION_H_

// Copyright 2013 Dmitry Vodopyanov

#ifndef CODE_DMITRY_VODOPYANOV_LIBRARY_LENGTHCONVERTORAPP_H_
#define CODE_DMITRY_VODOPYANOV_LIBRARY_LENGTHCONVERTORAPP_H_

#include <string>
#include "library/LengthConvertor.h"

#pragma pack(push, 1)
typedef struct {
    double value;
    LengthUnit UnitInput;
    LengthUnit UnitOutput;
} Expression;
#pragma pack(pop)

class LengthConvertorApp {
 public:
    LengthConvertorApp();

    std::string operator()(int argc, char** argv);

 private:
    std::string message_;

    void help(const char* appname);
    bool parseArguments(int argc, const char** argv, Expression* expr);
};

#endif  // CODE_DMITRY_VODOPYANOV_LIBRARY_LENGTHCONVERTORAPP_H_

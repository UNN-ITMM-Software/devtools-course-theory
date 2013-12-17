/* Copyright 2013 Pavel Korotaev */

#ifndef CODE_PAVEL_KOROTAEV_LIBRARY_WEIGHTCONVERTOR_APPLICATION_H_
#define CODE_PAVEL_KOROTAEV_LIBRARY_WEIGHTCONVERTOR_APPLICATION_H_

#include <string>
#include "library/WeightConvertor.h"

#pragma pack(push, 1)
typedef struct {
    double value;
    WeightUnit unit;
    WeightUnit UnitOutput;
} Expression;
#pragma pack(pop)

class WeightConvertorApplication {
 public:
    WeightConvertorApplication();

    std::string operator()(int argc, const char** argv);

 private:
    std::string message_;

    void help(const char* appname);
    bool parseArguments(int argc, const char** argv, Expression* expr);
};

#endif  // CODE_PAVEL_KOROTAEV_LIBRARY_WEIGHTCONVERTOR_APPLICATION_H_

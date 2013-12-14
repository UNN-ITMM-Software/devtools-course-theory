/* Copyright 2013 Denis Sabanov */
#ifndef CODE_DENIS_SABANOV_LIBRARY_AREACONVERTERAPP_H_
#define CODE_DENIS_SABANOV_LIBRARY_AREACONVERTERAPP_H_

#include <stdint.h>
#include <string>
#include "library/AreaConverter.h"

#pragma pack(push, 1)
typedef struct {
    double value;
    AreaType curUnit;
    AreaType newUnit;
} Expression;
#pragma pack(pop)

class AreaConverterApp {
 public:
    AreaConverterApp();

    std::string operator()(int argc, char** argv);
 private:
    std::string message_;

    void help(const char* appname);
    bool parseArguments(int argc, char** argv, Expression* expr);
};
#endif  // CODE_DENIS_SABANOV_LIBRARY_AREACONVERTERAPP_H_

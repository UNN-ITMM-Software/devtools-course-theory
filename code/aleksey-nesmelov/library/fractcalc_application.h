// Copyright 2013 Aleksey Nesmelov

#ifndef CODE_ALEKSEY_NESMELOV_LIBRARY_FRACTCALC_APPLICATION_H_
#define CODE_ALEKSEY_NESMELOV_LIBRARY_FRACTCALC_APPLICATION_H_

#include <string>

#pragma pack(push, 1)
typedef struct {
    int arg1;
    int arg2;
    int arg3;
    int arg4;
    char operation;
} Expression;
#pragma pack(pop)

class FractionCalculatorApplication {
 public:
    FractionCalculatorApplication();

    std::string operator()(int argc, const char** argv);

 private:
    std::string message;

    void help(const char* appname);
    bool parseArguments(int argc, const char** argv, Expression* expr);
};

#endif  // CODE_ALEKSEY_NESMELOV_LIBRARY_FRACTCALC_APPLICATION_H_

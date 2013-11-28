// Copyright 2013 Kirill Kornyakov

#ifndef CODE_KIRILL_KORNYAKOV_LAB5_LIBRARY_CALC_APPLICATION_H_
#define CODE_KIRILL_KORNYAKOV_LAB5_LIBRARY_CALC_APPLICATION_H_

#include <string>

#pragma pack(push, 1)
typedef struct {
    int arg1;
    int arg2;
    char operation;
} Expression;
#pragma pack(pop)

class CalculatorApplication {
 public:
    CalculatorApplication();

    std::string operator()(int argc, char** argv);

 private:
    std::string message;

    void help(const char* appname);
    Expression parseArguments(int argc, char** argv);
};

#endif  // CODE_KIRILL_KORNYAKOV_LAB5_LIBRARY_CALC_APPLICATION_H_

/* Copyright 2013 Dmitriy Gorokhov */

#ifndef CODE_DMITRIY_GOROKHOV_LIBRARY_QUADRATICEQUATIONAPPLICATION_H_
#define CODE_DMITRIY_GOROKHOV_LIBRARY_QUADRATICEQUATIONAPPLICATION_H_

#include <string.h>
#include <string>

#pragma pack(push, 1)
typedef struct {
    double a;
    double b;
    double c;
} Expression;
#pragma pack(pop)

class QuadraticEquationApplication {
 public:
    QuadraticEquationApplication();

    std::string operator()(int argc, const char** argv);

 private:
    std::string message;

    void help(const char* appname);
    double parseDouble(const char* arg);
    bool parseArguments(int argc, const char** argv, Expression* expr);
};

#endif  // CODE_DMITRIY_GOROKHOV_LIBRARY_QUADRATICEQUATIONAPPLICATION_H_

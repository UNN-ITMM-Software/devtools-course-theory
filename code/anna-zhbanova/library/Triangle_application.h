/* Copyright 2013 Anna Zhbanova */

#ifndef CODE_ANNA_ZHBANOVA_LIBRARY_TRIANGLE_APPLICATION_H_
#define CODE_ANNA_ZHBANOVA_LIBRARY_TRIANGLE_APPLICATION_H_

#include <string>
#include "library/Triangle.h"

#pragma pack(push, 1)
struct Expression {
    PointXY A;
    PointXY B;
    PointXY C;
    PointXY parameter;
    NameOfVertex nameOfStartVertex;
    NameOfVertex nameOfEndVertex;
    int operation;
    Expression(): A(PointXY()), B(PointXY()), C(PointXY()),
                  parameter(PointXY()), nameOfStartVertex(),
                  nameOfEndVertex(), operation(0) {
    }
};
#pragma pack(pop)

class TriangleApplication {
 public:
    TriangleApplication();

    std::string operator()(int argc, const char** argv);

 private:
    std::string message;

    void help(const char* appname);
    bool parseArguments(int argc, const char** argv, Expression* expr);
    float parseFloat(const char* arg);
    int parseInteger(const char* arg);
    NameOfVertex parseEnum(const char arg);
};

#endif  // CODE_ANNA_ZHBANOVA_LIBRARY_TRIANGLE_APPLICATION_H_

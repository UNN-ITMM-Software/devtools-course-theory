// Copyright 2013 Moshkov Yuriy

#ifndef CODE_MOSHKOV_YURIY_LIBRARY_DISTAPPLICATION_H_
#define CODE_MOSHKOV_YURIY_LIBRARY_DISTAPPLICATION_H_

#include <string>
#include "library/DistanceBetweenVectors.h"

#pragma pack(push, 1)
typedef struct {
    int sizeVector;
    float* vect1;
    float* vect2;
    TypeMetric typeMetric;
} Expression;
#pragma pack(pop)

class DistApplication
{
public:
    DistApplication();

    std::string operator()(int argc, char** argv);

private:
    std::string message_;

    void help(const char* appname);
    bool parseArguments(int argc, char** argv, Expression* expr);
};

#endif  // CODE_MOSHKOV_YURIY_LIBRARY_DISTAPPLICATION_H_

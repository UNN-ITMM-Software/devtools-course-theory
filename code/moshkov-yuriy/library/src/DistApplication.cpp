/* Copyright 2013 Moshkov Yuriy */

#include "library/DistApplication.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <sstream>
#include <string>

#include "library/DistanceBetweenVectors.h"

#if defined _WIN32 || defined _WIN64
#define strtok_r strtok_s
#endif

extern const char* arrTypeMetric[5];

const char* arrTypeMetric[5] = {"L1", "L2", "L3", "L4", "LInfinity"};

DistApplication::DistApplication() : message_("") {}

void DistApplication::help(const char* appname) {
    message_ += std::string("This is an application ")
             + "for calculate distance between vectors.\n\n"
             + "Please provide arguments in the following format:\n\n"
             + "  $ " + appname + " <sizeVector> <vector1> <vector2> "
             + "<typeMetric>\n\n"
             + "Where sizeVector is integer and > 0, both vectors have this "
             + "form: {element_1,...,element_sizeVector} "
             + "where all elements are float "
             + "and typeMetric is one of\n";
    for (int i = 0; i < 5; i++)
        message_ += std::string(arrTypeMetric[i])+ "\n";
}

float parseFloat(const char* arg);
float parseFloat(const char* arg) {
    char* end;
    float value = static_cast<float>(strtod(arg, &end));
    if (!end[0] && ((((value < FLT_MAX) && (value > FLT_MIN)) ||
        ((value > -FLT_MAX) && (value < -FLT_MIN))) || (value == 0))) {
          printf("%s is valid\n", arg);
     } else {
         printf("%s is invalid\n", arg);
         throw "wrong number format";
     }
    return value;
}

int parseInt(const char* arg);
int parseInt(const char* arg) {
    char* end;
    int value = static_cast<int>(strtol(arg, &end, 10));
    if (!end[0]) {
    } else {
        printf("%s is invalid\n", arg);
        throw "wrong number format";
    }
    return value;
}

float* getVector(char* str, int sizeVector) {
    float* vector = NULL;
    if ((str[0] == '{') && (str[strlen(str) - 1] == '}')) {
        vector = new float[sizeVector];
        char* strWithBracket = new char[strlen(str) - 2 + 1];
        strWithBracket[strlen(str) - 2] = '\0';
        strncpy(strWithBracket, str + 1, strlen(str) - 2);
        char *rest;
        char* charElem = strtok_r(strWithBracket, ",", &rest);
        int indElem = 0;
        while (charElem != NULL) {
            if (indElem == sizeVector) {
                indElem++;
                break;
            }
            try {
                vector[indElem++] = static_cast<float>(parseFloat(charElem));
            }
            catch(...) {
                throw "Wrong vector's elements format";
            }
            charElem = strtok_r(rest, ",", &rest);
        }
        if (indElem != sizeVector) {
            delete []vector;
            vector = NULL;
        }
    }
    return vector;
}

bool DistApplication::parseArguments(int argc, char** argv,
                                           Expression* expression) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 5) {
        message_ = "ERROR: Should be 4 arguments.\n\n";
        help(argv[0]);
        return false;
    }
    try {
        expression->sizeVector = static_cast<int>(parseInt(argv[1]));
    }
    catch(...) {
        message_ = "Wrong number format of size vector!\n";
        return false;
    }
    if (expression->sizeVector <= 0)    {
        message_ = "Wrong input size vector!\n";
        return false;
    }
    for (int i = 0; i < 5; i++)
        if (strcmp(argv[4], arrTypeMetric[i]) == 0)    {
            expression->typeMetric = static_cast<TypeMetric>(i + 1);
            break;
        } else if (i == 4) {
            message_ = "Wrong format of type metric!\n";
            return false;
        }
    try    {
        expression->vect1 = getVector(argv[2], expression->sizeVector);
        expression->vect2 = getVector(argv[3], expression->sizeVector);
    }
    catch(...) {
        message_ = "Wrong vector's elements format!\n";
        return false;
    }
    if ((expression->vect1 == NULL) || (expression->vect2 == NULL)) {
        message_ = "Wrong vector's format!\n";
        return false;
    }
    return true;
}

std::string DistApplication::operator()(int argc, char** argv) {
    Expression expression;

    bool returnCode = parseArguments(argc, argv, &expression);
    if (returnCode != true)
        return message_;
    float distance = DistanceBetweenVectors::CalculateDistance(expression.vect1
                , expression.vect2, expression.typeMetric,
                expression.sizeVector);
    std::ostringstream stream;
    stream << distance;
    message_ = stream.str();

    return message_;
}

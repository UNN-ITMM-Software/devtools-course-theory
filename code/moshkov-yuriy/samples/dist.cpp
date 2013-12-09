/* Copyright 2013 Moshkov Yuriy */
#include <DistanceBetweenVectors.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#if defined _WIN32 || defined _WIN64
    #define strtok_r strtok_s
#endif

#if defined(_MSC_VER)
    #define mystrncpy proxy_func
    void proxy_func(char *strDest, const char *strSource, size_t count) {
        strncpy_s(strDest, 256, strSource, count);
    }
#else
    #define mystrncpy strncpy
#endif

#pragma pack(push, 1)
typedef struct {
    int sizeVector;
    float* vect1;
    float* vect2;
    TypeMetric typeMetric;
} Expression;
#pragma pack(pop)

extern const char* arrTypeMetric[5];

const char* arrTypeMetric[5] = {"L1", "L2", "L3", "L4", "LInfinity"};

void help(const char* appname);
float* getVector(char* str, int sizeVector);
Expression parseArguments(int argc, char** argv);
float parseFloat(const char* arg);
int parseInt(const char* arg);

void help(const char* appname) {
    printf("This is an application ");
    printf("for calculate distance between vectors.\n\n");
    printf("Please provide arguments in the following format:\n\n");
    printf(" $ %s <sizeVector> <vector1> <vector2> <typeMetric>\n\n", appname);
    printf("Where sizeVector is integer and > 0, both vectors have this ");
    printf("form: {element_1,...,element_sizeVector} ");
    printf("where all elements are float ");
    printf("and typeMetric is one of\n");
    for (int i = 0; i < 5; i++)
        printf("%s\n", arrTypeMetric[i]);
}

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

float parseFloat(const char* arg) {
    char* end;
    float value = static_cast<float>(strtod(arg, &end));
    if (!end[0] && ((((value < FLT_MAX) && (value > FLT_MIN)) ||
        ((value > -FLT_MAX) && (value < -FLT_MIN))) || (value == 0.0))) {
        printf("%s is valid\n", arg);
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
        char* rest;
        strWithBracket[strlen(str) - 2] = '\0';
        mystrncpy(strWithBracket, str + 1, strlen(str) - 2);
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
        delete []strWithBracket;
    }
    return vector;
}

Expression parseArguments(int argc, char** argv) {
    if (argc == 1) {
        help(argv[0]);
        exit(0);
    } else if (argc != 5) {
        printf("ERROR: Should be 4 arguments.\n\n");
        help(argv[0]);
        exit(1);
    }
    Expression expression;
    try {
        expression.sizeVector = static_cast<int>(parseInt(argv[1]));
    }
    catch(...) {
        printf("Wrong number format of size vector!\n");
        exit(2);
    }
    if (expression.sizeVector <= 0)    {
        printf("Wrong input size vector!\n");
        exit(3);
    }
    for (int i = 0; i < 5; i++)
        if (strcmp(argv[4], arrTypeMetric[i]) == 0)    {
            expression.typeMetric = static_cast<TypeMetric>(i + 1);
            break;
        } else if (i == 4) {
            printf("Wrong format of type metric!\n");
            exit(4);
        }
    try {
        expression.vect1 = getVector(argv[2], expression.sizeVector);
        expression.vect2 = getVector(argv[3], expression.sizeVector);
    }
    catch(...) {
        printf("Wrong number format of vector's elements!\n");
        exit(5);
    }
    if ((expression.vect1 == NULL) || (expression.vect2 == NULL)) {
        printf("Wrong vector's format!\n");
        exit(6);
    }
    return expression;
}

int main(int argc, char** argv) {
    Expression expression = parseArguments(argc, argv);
    float distance = 0;
    distance = DistanceBetweenVectors::CalculateDistance(expression.vect1,
               expression.vect2, expression.typeMetric, expression.sizeVector);
    printf("distance = %f\n", distance);
    delete []expression.vect1;
    delete []expression.vect2;
    return 0;
}

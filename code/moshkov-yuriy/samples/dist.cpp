/* Copyright 2013 Moshkov Yuriy */
#include <DistanceBetweenVectors.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
float* getVector(char* str);
Expression parseArguments(int argc, char** argv);

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

float* getVector(char* str, int sizeVector) {
    float* vector = NULL;
    if ((str[0] == '{') && (str[strlen(str) - 1] == '}')) {
        vector = new float[sizeVector];
        char* strWithBracket = new char[strlen(str) - 2 + 1];
        char* rest;
        strWithBracket[strlen(str) - 2] = '\0';
        strncpy(strWithBracket, str + 1, strlen(str) - 2);
        char* charElem = strtok_r(strWithBracket, ",", &rest);
        int indElem = 0;
        while (charElem != NULL) {
            if (indElem == sizeVector) {
                indElem++;
                break;
            }
            try {
                vector[indElem++] = static_cast<float>(atof(charElem));
            }
            catch(...) {
                printf("Wrong vector's elements format!\n");
                exit(2);
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
        expression.sizeVector = static_cast<int>(atoi(argv[1]));
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
    expression.vect1 = getVector(argv[2], expression.sizeVector);
    expression.vect2 = getVector(argv[3], expression.sizeVector);
    if ((expression.vect1 == NULL) || (expression.vect2 == NULL)) {
        printf("Wrong vector's form!\n");
        exit(5);
    }
    return expression;
}

int main(int argc, char** argv) {
    Expression expression = parseArguments(argc, argv);
    float distance = 0;
    distance = DistanceBetweenVectors::CalculateDistance(expression.vect1,
               expression.vect2, expression.typeMetric, expression.sizeVector);
    printf("%f distance between source vectors in %s\n", distance,
            arrTypeMetric[static_cast<int>(expression.typeMetric - 1)]);
    return 0;
}

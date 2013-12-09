/* Copyright 2013 Aleksey Kostrov */

#if defined _WIN32 || defined _WIN64
#define rand_r rand_s
#define _CRT_RAND_S
#endif
#include <stdlib.h>

#include <Dichotomy_Search.h>

#define SIZE_FOR_PRINT 25
#define LEFT_BORDER_RANDOM 1
#define RIGHT_BORDER_RANDOM 50

#pragma pack(push, 1)
typedef struct {
    int size;
    int element;
} Expression;
#pragma pack(pop)

void help(const char* appname);
int parseInteger(const char* arg);
Expression parseArguments(int argc, char** argv);

void help(const char *appname) {
    printf("This is a dichotomy search application.\n\n");
    printf("Please provide arguments in the following format:\n\n");
    printf("  $ %s <size> <element>\n\n", appname);
    printf("Where both arguments are integer numbers.");
}

int parseInteger(const char *arg) {
    char* end;
    int value = static_cast<int>(strtol(arg, &end, 10));

    if (!end[0]) {
        printf("%s is valid\n", arg);
    } else {
        printf("%s is invalid\n", arg);
        throw "Wrong number format!";
    }

    return value;
}

Expression parseArguments(int argc, char **argv) {
    if (argc == 1) {
        help(argv[0]);
        exit(0);
    } else if (argc != 3) {
        printf("ERROR: Should be 2 arguments!\n\n");
        help(argv[0]);
        exit(1);
    }

    Expression expression;
    try {
        expression.size = static_cast<int>(parseInteger(argv[1]));
        expression.element = static_cast<int>(parseInteger(argv[2]));
    }
    catch(...) {
        printf("Wrong arguments format!\n");
        exit(2);
    }

    if (expression.size <= 0) {
        printf("Size of array must be more than zero!\n");
        exit(3);
    }

    return expression;
}

int main(int argc, char** argv) {
    Expression expr = parseArguments(argc, argv);
    const int ELEM_NOT_FOUND = -1;
    int * array;
    int returnCode;
    array = new int[expr.size];
    unsigned int seed = static_cast<unsigned int>(time(NULL));
    for (int i = 0; i < expr.size; i++)
        array[i] = static_cast<int>(rand_r(&seed) % RIGHT_BORDER_RANDOM)
                + LEFT_BORDER_RANDOM;
    array[0] = 54;
    if (expr.size < SIZE_FOR_PRINT) {
        printf("Generated array: ");
        for (int i = 0; i < expr.size; i++)
            printf(" %d ", array[i]);
        printf("\n");
    } else if (expr.size > 0) {
        printf("Array was generated automatically!\n");
    }
        DichotomySearch example1;
        returnCode = example1.Search(array, expr.element, expr.size);
        if (returnCode == ELEM_NOT_FOUND)
            printf("Element not found!\n");
        else
            printf("Index of search element: %d", returnCode+1);
    delete [] array;

    return 0;
}

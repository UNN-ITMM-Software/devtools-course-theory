/* Copyright 2013 Aleksey Kostrov */

#if defined _WIN32 || defined _WIN64
#define rand_r rand_s
#define _CRT_RAND_S
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>

#include "library/Dichotomy_Search_application.h"
#include "library/Dichotomy_Search.h"

#define SIZE_FOR_PRINT 25
#define LEFT_BORDER_RANDOM 1
#define RIGHT_BORDER_RANDOM 50

DichotomySearchApplication::DichotomySearchApplication() : message("") {}

void DichotomySearchApplication::help(const char* appname) {
    message += std::string("This is a dichotomy search application.\n\n")
            + "Please provide arguments in the following format:\n\n"
            + "  $ " + appname + " <size> <element>\n\n"
            + "Where both arguments are integer numbers.\n";
}

int DichotomySearchApplication::parseInteger(const char *arg) {
    char* end;
    int value = static_cast<int>(strtol(arg, &end, 10));

    if (end[0]) {
        throw "Wrong number format!";
    }

    return value;
}

bool DichotomySearchApplication::parseArguments(int argc,
                                                const char** argv,
                                                Expression* expr) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 3) {
        message = "ERROR: Should be 2 arguments!\n\n";
        help(argv[0]);
        return false;
    }
    try {
        expr->size = static_cast<int>(parseInteger(argv[1]));
        expr->element = static_cast<int>(parseInteger(argv[2]));
    }
    catch(...) {
        message = "Wrong arguments format!\n";
        return false;
    }

    if (expr->size <= 0) {
        printf("Size of array must be more than zero!\n");
        return false;
    }

    return true;
}

std::string DichotomySearchApplication::operator()(int argc,
                                                  const char** argv) {
    Expression expression;
    bool parseCode = parseArguments(argc, argv, &expression);
    if(parseCode != true)
        return message;
    std::ostringstream stream;
    const int ELEM_NOT_FOUND = -1;
    int * array;
    int returnCode;
    array = new int[expression.size];
    unsigned int seed = static_cast<unsigned int>(time(NULL));
    for (int i = 0; i < expression.size; i++)
        array[i] = static_cast<int>(rand_r(&seed) % RIGHT_BORDER_RANDOM)
                + LEFT_BORDER_RANDOM;
    array[0] = 54;
    if (expression.size < SIZE_FOR_PRINT) {
        stream << "Generated array: ";
        for (int i = 0; i < expression.size; i++)
            stream << array[i];
        stream << "\n";
    } else if (expression.size > 0) {
        stream << "Array was generated automatically!\n";
    }
    DichotomySearch example1;
    returnCode = example1.Search(array, expression.element, expression.size);
    if (returnCode == ELEM_NOT_FOUND) {
        stream << "Element not found!\n";
    } else {
        stream << "Index of search element: ";
        stream << returnCode+1;
    }
    delete [] array;
    message = stream.str();

    return message;
}

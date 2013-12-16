/* Copyright 2013 Alexandr Smirnov */

#include "library/sort_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "library/sort.h"

SorterApplication::SorterApplication() : message_("") {}

void SorterApplication::help(const char* appname) {
    message_ += std::string("This is an application of sorting arrays ")
             + "of integer numbers.\n\n"
             + "Please provide arguments in the following format:\n\n"
             + "  $ " + appname + " <sort method> <size of array>\n\n"
             + " <element[1]> <element[2]>... <element[size]> \n\n"
             + "Where all arguments but second are integer numbers, \n\n"
             + "third argument is the number of elements in the array,  \n\n"
             + "and second argument has type 'string' and values: \n\n"
             + "q - if you want to sort this by QUICKSORT \n\n"
             + "h - if you want to sort this by HEAPSORT \n\n"
             + "m - if you want to sort this by MERGESORT \n\n";
}

int64_t parseInteger(const char* arg);
int64_t parseInteger(const char* arg) {
    char* end;
    int64_t value = strtol(arg, &end, 10);

    if (end[0]) {
        throw "Wrong number format";
    }

    return value;
}

bool canCompute(const char* expr);
bool canCompute(const char* expr) {
  int arg = static_cast<int>(parseInteger(expr));
  if (arg == static_cast<int>(parseInteger(expr))) {
    return true;
  } else {
    return false;
  }
}

bool SorterApplication::parseArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != (atoi(argv[2]) + 3)) {
        message_ = "ERROR: The number of arguments must match \n\n";
        message_ += "value of second argument + 3.\n\n";
        help(argv[0]);
        return false;
    }

    try {
      for (int i = 2; i < argc; i++) {
        canCompute(argv[i]);
      }
    }
    catch(...) {
        message_ = "Wrong number format!\n";
        return false;
    }

    return true;
}

std::string SorterApplication::operator()(int argc, const char** argv) {
    bool returnCode = parseArguments(argc, argv);
    if (returnCode != true)
        return message_;

    int N = atoi(argv[2]);
    int* a = new int[N];

    for (int i = 0; i < N; i++)
      a[i] = atoi(argv[i + 3]);
    Sorter sorter;

    if (argv[1][0] == 'q')
      sorter.Sort(a, N, QUICKSORT);
    if (argv[1][0] == 'h')
      sorter.Sort(a, N, HEAPSORT);
    if (argv[1][0] == 'm')
      sorter.Sort(a, N, MERGESORT);

    std::ostringstream stream;
    stream << "Result of sorting:";

    for (int i = 0; i < N; i++)
        stream << " " << a[i];

    message_ = stream.str();

    delete [] a;
    return message_;
}

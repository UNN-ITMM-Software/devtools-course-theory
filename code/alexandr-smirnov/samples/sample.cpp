/* Copyright 2013 Alexandr Smirnov */

#include <sort.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

void help(const char* appname);
void parseArguments(int argc, char** argv);
int64_t parseInteger(const char* arg);
bool canCompute(const char* expr);

void help(const char* appname) {
    printf("This is an application of sorting arrays of integer numbers.\n\n");
    printf("Please provide arguments in the following format:\n\n");
    printf("  $ %s <sort method> <size of array>", appname);
    printf(" <element[1]> <element[2]>... <element[size]> \n\n");
    printf("Where all arguments but second are integer numbers, \n\n");
    printf("third argument is the number of elements in the array,  \n\n");
    printf("and second argument has type 'string' and values: \n\n");
    printf("q - if you want to sort this by QUICKSORT \n\n");
    printf("h - if you want to sort this by HEAPSORT \n\n");
    printf("m - if you want to sort this by MERGESORT \n\n");
}

bool canCompute(const char* expr) {
  int arg = static_cast<int>(parseInteger(expr));
  if (arg == static_cast<int>(parseInteger(expr))) {
    return true;
  } else {
    return false;
  }
}

int64_t parseInteger(const char* arg) {
    char* end;
    int64_t value = strtol(arg, &end, 10);
    if (!end[0]) {
        printf("%s is valid\n", arg);
    } else {
        printf("%s is invalid\n", arg);
        throw "wrong number format";
    }
    return value;
}

void parseArguments(int argc, char** argv) {
    if (argc == 1) {
        help(argv[0]);
        exit(0);
    } else {
      if (argc != (atoi(argv[2]) + 3)) {
          printf("ERROR: The number of arguments must match \n\n");
          printf("value of second argument + 3.\n\n");
          help(argv[0]);
          exit(1);
      }
      try {
        for (int i = 2; i < argc; i++) {
        canCompute(argv[i]);
        }
      }
      catch(...) {
        printf("Wrong number format!\n");
        exit(2);
      }
    }
}

int main(int argc, char** argv) {
    parseArguments(argc, argv);

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

    printf("Result of sorting: ");

    for (int i = 0; i < N; i++)
      printf("%d ", a[i]);

    delete [] a;
    return 0;
}

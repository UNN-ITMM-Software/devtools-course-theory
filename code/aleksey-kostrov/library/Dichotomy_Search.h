/* Copyright 2013 Aleksey Kostrov */

#ifndef CODE_ALEKSEY_KOSTROV_LIBRARY_DICHOTOMY_SEARCH_H_
#define CODE_ALEKSEY_KOSTROV_LIBRARY_DICHOTOMY_SEARCH_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class DichotomySearch {
 public:
    DichotomySearch();
    ~DichotomySearch();
    int **Preprocess(int *array, int size);
    int Search(int *array, int element, int size);
};

#endif  // CODE_ALEKSEY_KOSTROV_LIBRARY_DICHOTOMY_SEARCH_H_


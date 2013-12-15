/* Copyright 2013 Aleksey Kostrov */

#if defined _WIN32 || defined _WIN64
#define rand_r rand_s
#define _CRT_RAND_S
#endif

#include <library/Dichotomy_Search.h>

#define ELEM_NOT_FOUND -1
#define LEFT_BORDER_RANDOM 1
#define RIGHT_BORDER_RANDOM 50

DichotomySearch::DichotomySearch() {}

DichotomySearch::~DichotomySearch() {}

void DeleteMemory(int ** array, int size);

void DichotomySearch::SetUp(int *&array, int size) {
    array = new int[size];
    unsigned int seed = 12345;
    for (int i = 0; i < size; i++)
        array[i] = static_cast<int>(rand_r(&seed) % RIGHT_BORDER_RANDOM)
                + LEFT_BORDER_RANDOM;
    array[0] = 54;
    for (int i = 0; i < size; i++) {
        printf_s("%d", array[i]);
    }
}

int **DichotomySearch::Preprocess(int * array, int size) {
    int ** addit_array;
    addit_array = new int *[size];
    for (int i = 0; i < size; i++) {
        addit_array[i] = new int[2];
        addit_array[i][0] = i;
        addit_array[i][1] = array[i];
    }
    int min = addit_array[0][1], max = addit_array[0][1];
    for (int i = 1; i < size; i++) {
        if (addit_array[i][1] < min)
            min = addit_array[i][1];
        else if (addit_array[i][1] > max)
            max = addit_array[i][1];
    }
    int *C = new int[max - min + 1];
    int **B = new int*[size];
    for (int i = 0; i < size; i++)
        B[i] = new int[2];
    for (int i = 0; i < (max - min + 1); i++)
        C[i] = 0;
    for (int i = 0; i < size; i++)
        C[ addit_array[i][1] - min ]++;
    for (int i = 1; i < (max - min + 1); i++)
        C[i] += C[i - 1];
    for (int i = 0; i < size; i++) {
        B[ C[ addit_array[i][1] - min ] - 1 ][1] = addit_array[i][1];
        B[ C[ addit_array[i][1] - min ]-- - 1 ][0] = addit_array[i][0];
    }
    for (int i = 0; i < size; i++) {
        addit_array[i][1] = B[i][1];
        addit_array[i][0] = B[i][0];
    }
    DeleteMemory(B, size);
    delete [] C;
    return addit_array;
}

void DeleteMemory(int ** array, int size) {
    for (int i = 0; i < size; i++)
        delete [] array[i];
    delete [] array;
}

int DichotomySearch::Search(int * array, int element, int size) {
    int **addit_array = Preprocess(array, size);
    int leftborder, rightborder, middle, temp;
    leftborder = 0;
    rightborder = size - 1;
    while (1) {
        middle = (leftborder + rightborder) / 2;
        if (element < addit_array[middle][1]) {
            rightborder = middle - 1;
        } else if (element > addit_array[middle][1]) {
            leftborder = middle + 1;
        } else {
            temp = addit_array[middle][0];
            DeleteMemory(addit_array, size);
            return temp;
        }
        if (leftborder > rightborder) {
            DeleteMemory(addit_array, size);
            return  ELEM_NOT_FOUND;
        }
    }
}

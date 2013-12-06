/* Copyright 2013 Aleksey Kostrov */

#if defined _WIN32 || defined _WIN64
#define rand_r rand_s
#define _CRT_RAND_S
#endif

#include <stdlib.h>

#include <gtest/gtest.h>

#include <string>

#include "library/Dichotomy_Search.h"

#define LEFT_BORDER_RANDOM 1
#define RIGHT_BORDER_RANDOM 50

void randomInitialize(int*& array, int size) {
    array = new int[size];
    unsigned int seed = static_cast<unsigned int>(time(NULL));
    for (int i = 0; i < size; i++)
        array[i] = static_cast<int>(rand_r(&seed) % RIGHT_BORDER_RANDOM)
                + LEFT_BORDER_RANDOM;
    array[0] = 54;
}

class DichotomySearchTest : public ::testing:: Test {
 protected:
    DichotomySearch example1;
    const int ELEM_NOT_FOUND = -1;
};

TEST_F(DichotomySearchTest, can_Detect_Not_Found_Element) {
    int* array;
    randomInitialize(array, 50);
    EXPECT_EQ(ELEM_NOT_FOUND, example1.Search(array, -5, 50));
}

TEST_F(DichotomySearchTest, can_Detect_Element) {
    int* array;
    randomInitialize(array, 50);
    EXPECT_EQ(1, example1.Search(array, 54, 50));
}

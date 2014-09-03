/* Copyright 2013 Aleksey Kostrov */

#if defined _WIN32 || defined _WIN64
#define rand_r rand_s
#define _CRT_RAND_S
#endif
#include <stdio.h>
#include <stdlib.h>

#include <gtest/gtest.h>

#include <string>

#include "library/Dichotomy_Search.h"

#define LEFT_BORDER_RANDOM 1
#define RIGHT_BORDER_RANDOM 50

class DichotomySearchTest : public ::testing:: Test {
 protected:
    DichotomySearch example1;
    const int ELEM_NOT_FOUND = -1;
    int* array;
    int size = 20;
    virtual void SetUp() {
        array = new int[size];
        unsigned int seed = 10;
        for (int i = 0; i < size; i++)
            array[i] = static_cast<int>(rand_r(&seed) % RIGHT_BORDER_RANDOM)
                    + LEFT_BORDER_RANDOM;
    }
};

TEST_F(DichotomySearchTest, can_Detect_Not_Found_Element) {
    EXPECT_EQ(ELEM_NOT_FOUND, example1.Search(array, -5, 20));
    delete [] array;
}

TEST_F(DichotomySearchTest, can_Detect_Element) {
    EXPECT_EQ(3, example1.Search(array, 19, 20));
    delete [] array;
}

TEST_F(DichotomySearchTest, can_Work_Preprocess) {
    int** two_dim_array;
    two_dim_array = example1.Preprocess(array, 20);
    EXPECT_EQ(12, two_dim_array[4][1]);
    delete [] array;
}

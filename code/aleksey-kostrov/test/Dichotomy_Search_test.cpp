/* Copyright 2013 Aleksey Kostrov */

#include <stdlib.h>

#include <gtest/gtest.h>

#include <string>

#include "library/Dichotomy_Search.h"

class DichotomySearchTest : public ::testing:: Test {
 protected:
    DichotomySearch example1;
    const int ELEM_NOT_FOUND = -1;
};

TEST_F(DichotomySearchTest, can_Detect_Not_Found_Element) {
    int* array;
    example1.SetUp(array, 50);
    EXPECT_EQ(ELEM_NOT_FOUND, example1.Search(array, -5, 50));
    delete [] array;
}

TEST_F(DichotomySearchTest, can_Detect_Element) {
    int* array;
    example1.SetUp(array, 20);
    EXPECT_EQ(3, example1.Search(array, 19, 20));
    delete [] array;
}

TEST_F(DichotomySearchTest, can_Work_Preprocess) {
    int* array;
    int** two_dim_array;
    example1.SetUp(array, 20);
    two_dim_array = example1.Preprocess(array, 20);
    EXPECT_EQ(19, two_dim_array[3][1]);
    delete [] array;
}

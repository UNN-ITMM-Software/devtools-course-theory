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
    example1.SetUp(array, 50);
    EXPECT_EQ(0, example1.Search(array, 54, 50));
    delete [] array;
}

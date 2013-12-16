/* Copyright 2013 Alexandr Smirnov */

#include <gtest/gtest.h>

#include <limits.h>
#include <string>

#include "library/sort.h"

class SorterTest : public ::testing::Test {
 protected:
    Sorter sorter;
};

TEST_F(SorterTest, Can_Sort_Positive_Numbers_By_MergeSort) {
    int N = 3;
    int *a = new int[N];
    a[0] = 2;
    a[1] = 1;
    a[2] = 4;
    int *b = new int[N];
    b[0] = 1;
    b[1] = 2;
    b[2] = 4;
    sorter.Sort(a, N, MERGESORT);
    EXPECT_EQ(a, b);
    delete [] a;
    delete [] b;
}

/* Copyright 2013 Alexandr Smirnov */

#include <gtest/gtest.h>

#include <limits.h>
#include <string>
#include <vector>

#include "library/sort.h"

class SorterTest : public ::testing::Test {
 protected:
    Sorter sorter;
};

TEST_F(SorterTest, Can_Sort_Positive_Numbers_By_MergeSort) {
    unsigned int N = 3;
    std::vector <int> a(N);
    unsigned int i;
    a[0] = 2;
    a[1] = 1;
    a[2] = 4;
    std::vector <int> b(N);
    b[0] = 1;
    b[1] = 2;
    b[2] = 4;
    sorter.Sort(&a[0], static_cast<int>(N), MERGESORT);
    for (int i = 0; i < N; i++) {
    EXPECT_EQ(a[i], b[i]);
    }
}

TEST_F(SorterTest, Can_Sort_Numbers_By_HeapSort) {
    unsigned int N = 4;
    std::vector <int> a(N);
    unsigned int i;
    a[0] = 20;
    a[1] = -15;
    a[2] = 43;
    a[3] = -2;
    std::vector <int> b(N);
    b[0] = -15;
    b[1] = -2;
    b[2] = 20;
    b[3] = 43;
    sorter.Sort(&a[0], static_cast<int>(N), HEAPSORT);
    for (int i = 0; i < N; i++) {
    EXPECT_EQ(a[i], b[i]);
    }
}

TEST_F(SorterTest, Can_Sort_Large_Numbers_By_QuickSort) {
    unsigned int N = 4;
    std::vector <int> a(N);
    unsigned int i;
    a[0] = 20000000;
    a[1] = -15000000;
    a[2] = 43000000;
    a[3] = -2000000;
    std::vector <int> b(N);
    b[0] = -15000000;
    b[1] = -2000000;
    b[2] = 20000000;
    b[3] = 43000000;
    sorter.Sort(&a[0], static_cast<int>(N), QUICKSORT);
    for (int i = 0; i < N; i++) {
    EXPECT_EQ(a[i], b[i]);
    }
}

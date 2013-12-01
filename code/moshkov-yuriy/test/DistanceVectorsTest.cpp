// Copyright 2013 Moshkov Yuriy

#include <gtest/gtest.h>

#include <float.h>
#include <string>

#include "library/DistanceBetweenVectors.h"

class DistanceTest : public ::testing::Test {
};

TEST_F(DistanceTest, Can_CalculteDistance_In_L1) {
    float vect1[] = {3.0, 5, 40};
    float vect2[] = {43.f, 9.9f, 33.f};
    EXPECT_EQ(51.9f, DistanceBetweenVectors::CalculateDistance(vect1, vect2,
                                                              L1, 3));
}

TEST_F(DistanceTest, Can_CalculteDistance_In_L2) {
    float vect1[] = {1, 7.0, 51, 40};
    float vect2[] = {3.f, 99.11f, -30.f, 0.0f};
    EXPECT_EQ(129.031982f, DistanceBetweenVectors::CalculateDistance(vect1,
                                                             vect2, L2, 4));
}

TEST_F(DistanceTest, Can_CalculteDistance_In_L3) {
    float vect1[] = {7.99f, 40.f};
    float vect2[] = {3.f, 11.11f};
    EXPECT_EQ(28.939541f, DistanceBetweenVectors::CalculateDistance(vect1,
                                                             vect2, L3, 2));
}

TEST_F(DistanceTest, Can_CalculteDistance_In_L4) {
    float vect1[] = {0, 4.0};
    float vect2[] = {0.0, 1.0};
    EXPECT_EQ(3.000000f, DistanceBetweenVectors::CalculateDistance(vect1,
                                                             vect2, L4, 2));
}

TEST_F(DistanceTest, Can_CalculteDistance_In_LInfinity) {
    float vect1[] = {9.f, 3.55f, 8.f};
    float vect2[] = {1.f, 1.190f, 7.f};
    EXPECT_EQ(8, DistanceBetweenVectors::CalculateDistance(vect1, vect2,
                                                              LInfinity, 3));
}

TEST_F(DistanceTest, Do_Throw_Exception_When_Dist_Is_Larger_Than_FLT_MAX) {
    float vect1[] = {FLT_MAX, 8};
    float vect2[] = {0, 1};
    EXPECT_THROW(DistanceBetweenVectors::CalculateDistance(vect1, vect2,
                                                   L1, 2), std::string);
}

TEST_F(DistanceTest, Do_Throw_Exception_When_Dist_Is_Less_Than_FLT_MIN) {
    float vect1[] = {FLT_MIN, 0};
    float vect2[] = {FLT_MIN / 2, 0};
    EXPECT_THROW(DistanceBetweenVectors::CalculateDistance(vect1, vect2,
                                                   L1, 2), std::string);
}

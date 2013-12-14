/* Copyright 2013 Dmitriy Gorokhov */

#include <gtest/gtest.h>

#include <string>

#include "library/QuadraticEquation.h"

class QuadraticEquationTest : public ::testing::Test {
 protected:
    QuadraticEquation quadEq;
    double Root1, Root2;
};

TEST_F(QuadraticEquationTest, can_Detect_Equation_With_No_Real_Roots) {
    quadEq.SetCoefficients(1, 0, 4);
    EXPECT_EQ(NOREALROOT, quadEq.Solve(&Root1, &Root2));
}

TEST_F(QuadraticEquationTest, can_Solve_Equation_With_One_Root) {
    quadEq.SetCoefficients(1, 2, 1);
    EXPECT_EQ(ONEROOT, quadEq.Solve(&Root1, &Root2));
}

TEST_F(QuadraticEquationTest, can_Solve_Equation_With_Two_Root) {
    quadEq.SetCoefficients(1, 2, -1);
    EXPECT_EQ(TWOROOTS, quadEq.Solve(&Root1, &Root2));
}

TEST_F(QuadraticEquationTest, can_Solve_Equation_With_Integer_Coefficients) {
    quadEq.SetCoefficients(1, 2, -3);
    quadEq.Solve(&Root1, &Root2);
    EXPECT_EQ(1, Root1);
    EXPECT_EQ(-3, Root2);
}

TEST_F(QuadraticEquationTest, can_Solve_Equation_With_Real_Coefficients) {
    quadEq.SetCoefficients(1.8, 4.6, -7.69);
    quadEq.Solve(&Root1, &Root2);
    EXPECT_EQ(1.1522300970252934, Root1);
    EXPECT_EQ(-3.707785652580849, Root2);
}

TEST_F(QuadraticEquationTest, can_Solve_Equation_With_Big_Coefficients) {
    quadEq.SetCoefficients(100000, 200000, -7000000);
    quadEq.Solve(&Root1, &Root2);
    EXPECT_EQ(7.426149773176359, Root1);
    EXPECT_EQ(-9.426149773176359, Root2);
}

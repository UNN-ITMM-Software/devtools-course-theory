// Copyright 2013 Kirill Kornyakov

#include <gtest/gtest.h>

#include <limits.h>
#include <string>

#include "library/simplecalc.h"

class CalculatorTest : public ::testing::Test {
 protected:
    // NOTE: here you can put your init/deinit code
    // virtual void SetUp() {}
    // virtual void TearDown() {}

    SimpleCalculator calc;
};

TEST_F(CalculatorTest, Can_Add) {
    EXPECT_EQ(2 + 2, calc.Add(2, 2));
}

TEST_F(CalculatorTest, Do_Throw_Exception_When_Sum_Is_Larger_Than_INT_MAX) {
    EXPECT_THROW(calc.Add(INT_MAX, INT_MAX), std::string);
}

TEST_F(CalculatorTest, Do_Throw_Exception_When_Sum_Is_Less_Than_Minus_INT_MAX) {
    EXPECT_THROW(calc.Add(-INT_MAX, -INT_MAX), std::string);
}

TEST_F(CalculatorTest, Can_Add_Negative_Numbers) {
    EXPECT_EQ(-30, calc.Add(-20, -10));
}

TEST_F(CalculatorTest, Can_Sub) {
    EXPECT_EQ(0, calc.Sub(10, 10));
}

TEST_F(CalculatorTest, Can_Sub_Thousands) {
    EXPECT_EQ(-3000, calc.Sub(4000, 7000));
}

TEST_F(CalculatorTest, Do_Throw_Exception_When_Diff_Is_Larger_Than_INT_MAX) {
    EXPECT_THROW(calc.Sub(INT_MAX, -INT_MAX), std::string);
}

TEST_F(CalculatorTest, Do_Throw_Exception_When_Diff_Is_Less_Than_Neg_INT_MAX) {
    EXPECT_THROW(calc.Sub(-INT_MAX, INT_MAX), std::string);
}

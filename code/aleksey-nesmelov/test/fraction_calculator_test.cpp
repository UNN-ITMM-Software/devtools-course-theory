// Copyright 2013 Aleksey Nesmelov

#include <gtest/gtest.h>
#include <string>

#include "library/fractcalc.h"

class FractionTest : public ::testing::Test {
 protected:
    void SetUpResultFraction(int num1, int denom1,
            int num2, int denom2, char operation) {
        fract1.SetNumenator(num1);
        fract1.SetDenominator(denom1);
        fract2.SetNumenator(num2);
        fract2.SetDenominator(denom2);

        switch (operation) {
         case '+':
            result = Fraction::Add(fract1, fract2);
            break;
         case '-':
            result = Fraction::Subtract(fract1, fract2);
            break;
         case '*':
            result = Fraction::Multiply(fract1, fract2);
            break;
         case '/':
            result = Fraction::Divide(fract1, fract2);
            break;
        }
    }

    Fraction fract1;
    Fraction fract2;
    Fraction result;
};

TEST_F(FractionTest, can_Add_Positive_Fractions) {
    SetUpResultFraction(1, 3, 1, 2, '+');
    EXPECT_EQ(Fraction(5, 6), result);
}

TEST_F(FractionTest, can_Sub_Positive_Fractions) {
    SetUpResultFraction(1, 4, 3, 5, '-');
    EXPECT_EQ(Fraction(-7, 20), result);
}

TEST_F(FractionTest, can_Mult_Positive_Fractions) {
    SetUpResultFraction(2, 3, 3, 4, '*');
    EXPECT_EQ(Fraction(1, 2), result);
}

TEST_F(FractionTest, can_Div_Positive_Fractions) {
    SetUpResultFraction(1, 3, 2, 3, '/');
    EXPECT_EQ(Fraction(1, 2), result);
}

TEST_F(FractionTest, can_Add_Negative_Fractions) {
    SetUpResultFraction(-1, 3, -1, 2, '+');
    EXPECT_EQ(Fraction(-5, 6), result);
}

TEST_F(FractionTest, can_Sub_Negative_Fractions) {
    SetUpResultFraction(-1, 4, -3, 5, '-');
    EXPECT_EQ(Fraction(7, 20), result);
}

TEST_F(FractionTest, can_Mult_Negative_Fractions) {
    SetUpResultFraction(-2, 3, -3, 4, '*');
    EXPECT_EQ(Fraction(1, 2), result);
}

TEST_F(FractionTest, can_Div_Negative_Fractions) {
    SetUpResultFraction(-1, 3, -2, 3, '/');
    EXPECT_EQ(Fraction(1, 2), result);
}

TEST_F(FractionTest, can_Enter_Fractions_With_Negative_Denominator) {
    SetUpResultFraction(1, -3, 2, -3, '*');
    EXPECT_EQ(Fraction(2, 9), result);
}

TEST_F(FractionTest,
    Do_Throw_Exception_When_Enter_Fractions_With_Zero_Denominator) {
    EXPECT_THROW(result.SetDenominator(0), std::string);
}

TEST_F(FractionTest, Do_Throw_Exception_When_Div_Fractions_With_Zero_Divisor) {
    fract2.SetNumenator(0);
    EXPECT_THROW(Fraction::Divide(fract1, fract2), std::string);
}

TEST_F(FractionTest, canCompareFractions) {
    SetUpResultFraction(1, 2, 1, 2, '*');
    EXPECT_TRUE(fract1 == fract2);
}

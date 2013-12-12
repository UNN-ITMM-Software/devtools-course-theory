// Copyright 2013 Aleksey Nesmelov

#include <gtest/gtest.h>
#include <string>
#include "library/fractcalc.h"

TEST(FractionTest, can_Add_Positive_Fractions) {
    Fraction a(1, 3);
    Fraction b(1, 2);

    EXPECT_EQ(Fraction(5, 6), a + b);
}

TEST(FractionTest, can_Sub_Positive_Fractions) {
    Fraction a(1, 4);
    Fraction b(3, 5);

    EXPECT_EQ(Fraction(-7, 20), a - b);
}

TEST(FractionTest, can_Mult_Positive_Fractions) {
    Fraction a(2, 3);
    Fraction b(3, 4);

    EXPECT_EQ(Fraction(1, 2), a * b);
}

TEST(FractionTest, can_Div_Positive_Fractions) {
    Fraction a(1, 3);
    Fraction b(2, 3);

    EXPECT_EQ(Fraction(1, 2), a / b);
}

TEST(FractionTest, can_Add_Negative_Fractions) {
    Fraction a(-1, 3);
    Fraction b(-1, 2);

    EXPECT_EQ(Fraction(-5, 6), a + b);
}

TEST(FractionTest, can_Sub_Negative_Fractions) {
    Fraction a(-1, 4);
    Fraction b(-3, 5);

    EXPECT_EQ(Fraction(7, 20), a - b);
}

TEST(FractionTest, can_Mult_Negative_Fractions) {
    Fraction a(-2, 3);
    Fraction b(-3, 4);

    EXPECT_EQ(Fraction(1, 2), a * b);
}

TEST(FractionTest, can_Div_Negative_Fractions) {
    Fraction a(-1, 3);
    Fraction b(-2, 3);

    EXPECT_EQ(Fraction(1, 2), a / b);
}

TEST(FractionTest, can_Enter_Fractions_With_Negative_Denominator) {
    Fraction a(2, -9);

    EXPECT_EQ(Fraction(-2, 9), a);
}

TEST(FractionTest,
    Do_Throw_Exception_When_Enter_Fractions_With_Zero_Denominator) {
    EXPECT_THROW(Fraction(5, 0), std::string);
}

TEST(FractionTest, Do_Throw_Exception_When_Div_Fractions_With_Zero_Divisor) {
    Fraction a(1, 5);
    Fraction b(0, 1);
    EXPECT_THROW(a / b, std::string);
}

TEST(FractionTest, canCompareFractions) {
    Fraction a(1, 2);
    Fraction b(1, 2);
    EXPECT_TRUE(a == b);
}

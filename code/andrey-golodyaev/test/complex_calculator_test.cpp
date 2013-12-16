/* Copyright 2013 Andrey Golodyaev */

#include <gtest/gtest.h>
#include <string>

#include "library/complexcalc.h"

TEST(AppTest, calc_can_Add_Numbers) {
    ComplexNumber a(1, 2);
    ComplexNumber b(2, -3);
    ComplexNumber res(3, -1);
    EXPECT_EQ(res, a + b);
}

TEST(AppTest, calc_can_Sub_Numbers) {
    ComplexNumber a(0, 1);
    ComplexNumber b(1, -1);
    ComplexNumber res(-1, 2);
    EXPECT_EQ(res, a - b);
}

TEST(AppTest, calc_can_Mul_Numbers) {
    ComplexNumber a(1, 1);
    ComplexNumber b(1, 1);
    ComplexNumber res(0, 2);
    EXPECT_EQ(res, a * b);
}

TEST(AppTest, calc_can_Div_Numbers) {
    ComplexNumber a(1, 1);
    ComplexNumber b(0, 1);
    ComplexNumber res(1, -1);
    EXPECT_EQ(res, a / b);
}

TEST(AppTest, calc_can_not_Div_by_Zero) {
    ComplexNumber a(1, 1);
    ComplexNumber b(0, 0);
    EXPECT_THROW(a / b, std::string);
}

TEST(AppTest, calc_can_Parse_Complex_Number) {
    ComplexNumber a;
    char str[35]="1+i";
    a.Input(str);
    ComplexNumber b(1, 1);
    EXPECT_EQ(a, b);
}

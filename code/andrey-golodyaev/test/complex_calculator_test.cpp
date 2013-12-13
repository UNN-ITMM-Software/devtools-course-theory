/* Copyright 2013 Andrey Golodyaev */

#include <gtest/gtest.h>
#include <string>

#include "library/complexcalc.h"

class ComplexTest : public ::testing::Test {
 protected:
     void GetResult(ComplexNumber a, ComplexNumber b, char operation) {
         switch (operation) {
          case '+':
              result = a + b;
              break;
          case '-':
              result = a - b;
              break;
          case '*':
              result = a * b;
              break;
          case '/':
              result = a / b;
              break;
         }
     }
     bool CheckResult(ComplexNumber a, ComplexNumber b) {
         bool returnCode = true;
         const double eps = 0.00001;
         if ((a.GetReal() - b.GetReal()) > eps ||
             (a.GetReal() - b.GetReal()) < -eps ||
             (a.GetImaginary() - b.GetImaginary()) > eps ||
             (a.GetImaginary() - b.GetImaginary()) < -eps)
             returnCode = false;
         return returnCode;
     }
     ComplexNumber result;
};

TEST_F(ComplexTest, calc_can_Add_Numbers) {
    ComplexNumber a(1, 2);
    ComplexNumber b(2, -3);
    ComplexNumber res(3, -1);
    GetResult(a, b, '+');
    EXPECT_TRUE(CheckResult(res, result));
}

TEST_F(ComplexTest, calc_can_Sub_Numbers) {
    ComplexNumber a(0, 1);
    ComplexNumber b(1, -1);
    ComplexNumber res(-1, 2);
    GetResult(a, b, '-');
    EXPECT_TRUE(CheckResult(res, result));
}

TEST_F(ComplexTest, calc_can_Mul_Numbers) {
    ComplexNumber a(1, 1);
    ComplexNumber b(1, 1);
    ComplexNumber res(0, 2);
    GetResult(a, b, '*');
    EXPECT_TRUE(CheckResult(res, result));
}

TEST_F(ComplexTest, calc_can_Div_Numbers) {
    ComplexNumber a(1, 1);
    ComplexNumber b(0, 1);
    ComplexNumber res(1, -1);
    GetResult(a, b, '/');
    EXPECT_TRUE(CheckResult(res, result));
}

TEST_F(ComplexTest, calc_can_not_Div_by_Zero) {
    ComplexNumber a(1, 1);
    ComplexNumber b(0, 0);
    EXPECT_THROW(a / b, std::string);
}

TEST_F(ComplexTest, calc_can_Parse_Complex_Number) {
    ComplexNumber a;
    char str[35]="1+i";
    a.Input(str);
    ComplexNumber b(1, 1);
    EXPECT_TRUE(CheckResult(a, b));
}

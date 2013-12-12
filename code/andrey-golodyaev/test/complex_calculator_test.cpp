/* Copyright 2013 Andrey Golodyaev */

#include <gtest/gtest.h>
#include <string>

#include "library/complexcalc.h"

class ComplexTest : public ::testing::Test {
 protected:
     void GetResult(const char *sa, const char *sb, char operation) {
         ComplexNumber a;
         ComplexNumber b;
         a.Input(sa);
         b.Input(sb);

         switch (operation) {
          case '+':
              result = ComplexNumber::Add(a, b);
              break;
          case '-':
              result = ComplexNumber::Sub(a, b);
              break;
          case '*':
              result = ComplexNumber::Mul(a, b);
              break;
          case '/':
              result = ComplexNumber::Div(a, b);
              break;
         }
     }
     bool CheckResult(const char *sa, ComplexNumber b) {
         ComplexNumber a;
         a.Input(sa);
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
    GetResult("1+2*i", "2-3i", '+');
    EXPECT_TRUE(CheckResult("3-i", result));
}

TEST_F(ComplexTest, calc_can_Sub_Numbers) {
    GetResult("i", "1-i", '-');
    EXPECT_TRUE(CheckResult("-1+2*i", result));
}

TEST_F(ComplexTest, calc_can_Mul_Numbers) {
    GetResult("1+i", "1+i", '*');
    EXPECT_TRUE(CheckResult("2*i", result));
}

TEST_F(ComplexTest, calc_can_Div_Numbers) {
    GetResult("1+i", "i", '/');
    EXPECT_TRUE(CheckResult("1-i", result));
}

TEST_F(ComplexTest, calc_can_not_Div_by_Zero) {
    ComplexNumber a(1, 1);
    ComplexNumber b(0, 0);
    EXPECT_THROW(ComplexNumber::Div(a, b), std::string);
}

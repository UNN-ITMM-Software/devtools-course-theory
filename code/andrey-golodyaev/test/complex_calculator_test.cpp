/* Copyright 2013 Andrey Golodyaev */

#include <gtest/gtest.h>
#include <string>

#include "library/complexcalc.h"

class ComplexTest : public ::testing::Test {
 protected:
     void GetResult(char *sa, char *sb, char operation) {
         a.Input(sa);
         b.Input(sb);
         
         switch (operation) {
          case '+':
              result = ComplexCalculator::Add(a, b);
              break;
          case '-':
              result = ComplexCalculator::Sub(a, b);
              break;
          case '*':
              result = ComplexCalculator::Multi(a, b);
              break;
          case '/':
              result = ComplexCalculator::Div(a, b);
              break;
         }
     }
     bool CheckResult(char *sa, ComplexCalculator b) {
         ComplexCalculator a;
         a.Input(sa);
         bool returnCode = true;
         if (a.GetReal() != b.GetReal() || a.GetReal() != b.GetImaginary())
             returnCode = false;
         return returnCode;
     }

     ComplexCalculator a;
     ComplexCalculator b;
     ComplexCalculator result;
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
    ComplexCalculator a(1, 1);
    ComplexCalculator b(0, 0);
    EXPECT_THROW(ComplexCalculator::Div(a, b), std::string);
}
 

 

/* Copyright 2013 Vasiliy Kumaev */

#include <gtest/gtest.h>
#include <float.h>
#include <string>
#include "library/CurrencyConvert.h"

class CurrencyConvertorTest : public ::testing::Test {
 protected:
    CurrencyConvert Conv;
};

TEST_F(CurrencyConvertorTest, Can_Convert_Ruble_to_Dollar) {
    EXPECT_EQ(6.000000, Conv.Convert({200, Ruble}, Dollar).value);
}

TEST_F(CurrencyConvertorTest, Can_Convert_Euro_to_Dollar) {
    EXPECT_EQ(74.000000, Conv.Convert({100, Euro}, Dollar).value);
}

TEST_F(CurrencyConvertorTest, Can_Convert_Pound_to_Ruble) {
    EXPECT_EQ(2650.000000, Conv.Convert({50, Pound}, Ruble).value);
}

TEST_F(CurrencyConvertorTest, Can_Convert_Euro_to_Pound) {
    Currency currency;
    currency.value = 33 * 0.74 / 1.59;
    EXPECT_EQ(currency.value, Conv.Convert({33, Euro}, Pound).value);
}

TEST_F(CurrencyConvertorTest, Can_Detect_Negative_Number) {
    EXPECT_EQ(-1.000000, Conv.Convert({-14, Pound}, Ruble).value);
}

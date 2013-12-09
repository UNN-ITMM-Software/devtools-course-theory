/* Copyright 2013 Vasiliy Kumaev */

#include <gtest/gtest.h>
#include <float.h>
#include <string>
#include "library/CurrencyConvert.h"

class CurrencyConvertorTest : public ::testing::Test {
 protected:
    // NOTE: here you can put your init/deinit code
    // virtual void SetUp() {}
    // virtual void TearDown() {}

    CurrencyConvert Conv;
};

TEST_F(CurrencyConvertorTest, Can_Convert_Ruble_to_Dollar) {
    EXPECT_EQ(6.000000, Conv.Convert({200, Ruble}, Dollar).value);
}

TEST_F(CurrencyConvertorTest, Can_Convert_Euro_to_Dollar) {
    EXPECT_EQ(74.000000, Conv.Convert({100, Euro}, Dollar).value);
}

TEST_F(CurrencyConvertorTest,
       Do_Throw_Exception_When_Value_Is_Larger_Than_DBL_MAX) {
    EXPECT_THROW(Conv.Convert({DBL_MAX+9999999999, Euro}, Ruble),
                 std::string);
}

TEST_F(CurrencyConvertorTest,
       Do_Throw_Exception_When_Value_Is_Less_Than_Minus_DBL_MAX) {
    EXPECT_EQ(-1.000000, Conv.Convert({-DBL_MAX, Dollar}, Ruble).value);
}

TEST_F(CurrencyConvertorTest, Can_Detect_Negative_Number) {
    EXPECT_EQ(-1.000000, Conv.Convert({-14, Pound}, Ruble).value);
}

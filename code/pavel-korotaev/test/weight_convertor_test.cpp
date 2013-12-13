// Copyright 2013 Pavel Korotaev

#include <gtest/gtest.h>
#include <float.h>
#include <string>
#include "library/WeightConvertor.h"

class WeightConvertorTest : public ::testing::Test {
 protected:
    WeightConvertor Conv;
};

TEST_F(WeightConvertorTest, Can_Convert_Ton_to_Kilograms) {
    EXPECT_EQ(7100.000000, Conv.ConvertTo({7.1, Ton}, Kilograms).value);
}

TEST_F(WeightConvertorTest,
       Do_Throw_Exception_When_Value_Is_Larger_Than_DBL_MAX) {
    EXPECT_THROW(Conv.ConvertTo({DBL_MAX+9999999999, Ton}, Kilograms),
                 std::string);
}

TEST_F(WeightConvertorTest,
       Do_Throw_Exception_When_Value_Is_Less_Than_Minus_DBL_MAX) {
    EXPECT_EQ(-1.000000, Conv.ConvertTo({-DBL_MAX, Ton}, Kilograms).value);
}

TEST_F(WeightConvertorTest, Can_Detect_Negative_Number) {
    EXPECT_EQ(-1.000000, Conv.ConvertTo({-14, Grams}, Stone).value);
}

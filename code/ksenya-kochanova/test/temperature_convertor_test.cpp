/* Copyright 2013 Ksenya Kochanova */
#include <gtest/gtest.h>

#include <limits.h>
#include <string>

#include "library/TemperatureConverter.h"

class TempConvTest : public ::testing::Test {
 protected:
    TemperatureConvertor tempconv;
};

TEST_F(TempConvTest, Do_Throw_Exception_When_Value_For_Celsius_Is_Wrong) {
    EXPECT_THROW(tempconv.Convert(-300, Celsius, Newton), std::string);
}
TEST_F(TempConvTest, Do_Throw_Exception_When_Value_For_Kelvin_Is_Wrong) {
    EXPECT_THROW(tempconv.Convert(-3, Kelvin, Newton), std::string);
}
TEST_F(TempConvTest, Do_Throw_Exception_When_Value_For_Newton_Is_Wrong) {
    EXPECT_THROW(tempconv.Convert(-100, Newton, Kelvin), std::string);
}
TEST_F(TempConvTest, Do_Throw_Exception_When_Value_For_Fahrenheit_Is_Wrong) {
    EXPECT_THROW(tempconv.Convert(-500, Fahrenheit, Newton), std::string);
}

TEST_F(TempConvTest, Can_Convert_Kelvin_To_Celsius) {
    EXPECT_EQ(-273.15, tempconv.Convert(0, Kelvin, Celsius));
}

TEST_F(TempConvTest, Can_Convert_Celsius_To_Newton) {
    EXPECT_EQ(1.65, tempconv.Convert(5, Celsius, Newton));
}

TEST_F(TempConvTest, Can_Convert_Fahrenheit_To_Celsius) {
    EXPECT_EQ(-26.4444, tempconv.Convert(10, Fahrenheit, Celsius));
}

TEST_F(TempConvTest, Can_Convert_Newton_To_Fahrenheit) {
    EXPECT_EQ(57.6, tempconv.Convert(0, Newton, Fahrenheit));
}

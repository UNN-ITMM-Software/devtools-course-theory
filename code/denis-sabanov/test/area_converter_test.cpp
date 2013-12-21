// Copyright 2013 Denis Sabanov

#include <gtest/gtest.h>
#include <float.h>
#include <string>
#include "library/AreaConverter.h"

class AreaConverterTest : public ::testing::Test {
 protected:
    AreaConverter Converter;
};

TEST_F(AreaConverterTest, Can_Convert_sFoot_to_sMeter) {
    Converter.SetValue(100);
    Converter.SetAreaType(sFoot);
    EXPECT_EQ(9.29, Converter.ConvertToNewType(sMeter));
}

TEST_F(AreaConverterTest, Can_Convert_sMeter_to_ar) {
    Converter.SetValue(100);
    Converter.SetAreaType(sMeter);
    EXPECT_EQ(1, Converter.ConvertToNewType(ar));
}

TEST_F(AreaConverterTest, Can_Convert_ar_to_sKilometer) {
    Converter.SetValue(1.65);
    Converter.SetAreaType(ar);
    double value = 1.65/10000;
    EXPECT_EQ(value, Converter.ConvertToNewType(sKilometer));
}

TEST_F(AreaConverterTest, Can_Convert_acre_to_sFoot) {
    Converter.SetValue(1.36);
    Converter.SetAreaType(acre);
    double value = 1.36*4047/0.0929;
    EXPECT_EQ(value, Converter.ConvertToNewType(sFoot));
}

TEST_F(AreaConverterTest, Can_Convert_acre_to_sMeter) {
    Converter.SetValue(10.25);
    Converter.SetAreaType(acre);
    double value = 10.25*4047;
    EXPECT_EQ(value, Converter.ConvertToNewType(sMeter));
}

TEST_F(AreaConverterTest, Can_Convert_hectare_to_sFoot) {
    Converter.SetValue(0.5);
    Converter.SetAreaType(hectare);
    double value = 0.5*10000/0.0929;
    EXPECT_EQ(value, Converter.ConvertToNewType(sFoot));
}

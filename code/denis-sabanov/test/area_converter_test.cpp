// Copyright 2013 Denis Sabanov

#include <gtest/gtest.h>
#include <float.h>
#include <string>
#include "library/AreaConverter.h"

class AreaConverterTest : public ::testing::Test {
 protected:
    // NOTE: here you can put your init/deinit code
    // virtual void SetUp() {}
    // virtual void TearDown() {}

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

TEST_F(AreaConverterTest, Can_Convert_acre_to_sFoot) {
    Converter.SetValue(10);
    Converter.SetAreaType(acre);
    EXPECT_EQ(435630, Converter.ConvertToNewType(sFoot));
}

TEST_F(AreaConverterTest, Can_Convert_ar_to_sKilometer) {
    Converter.SetValue(1.65);
    Converter.SetAreaType(ar);
    EXPECT_EQ(0.000165, Converter.ConvertToNewType(sKilometer));
}

TEST_F(AreaConverterTest, Can_Convert_sFoot_to_hectare) {
    Converter.SetValue(100);
    Converter.SetAreaType(sFoot);
    EXPECT_EQ(0.000929, Converter.ConvertToNewType(hectare));
}

TEST_F(AreaConverterTest, Can_Convert_sKilometer_to_acre) {
    Converter.SetValue(25);
    Converter.SetAreaType(sKilometer);
    EXPECT_EQ(6177.42, Converter.ConvertToNewType(acre));
}

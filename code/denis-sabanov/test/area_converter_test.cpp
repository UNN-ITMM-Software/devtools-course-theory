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

TEST_F(AreaConverterTest, Can_Convert_ar_to_sKilometer) {
    Converter.SetValue(1.65);
    Converter.SetAreaType(ar);
    EXPECT_EQ(0.000165, Converter.ConvertToNewType(sKilometer));
}

TEST_F(AreaConverterTest, Can_Convert_acre_to_sFoot) {
    Converter.SetValue(1.36);
    Converter.SetAreaType(acre);
    EXPECT_EQ(59245.6, Converter.ConvertToNewType(sFoot));
}

TEST_F(AreaConverterTest, Can_Convert_acre_to_sMeter) {
    Converter.SetValue(10.25);
    Converter.SetAreaType(acre);
    EXPECT_EQ(41481.8, Converter.ConvertToNewType(sMeter));
}

TEST_F(AreaConverterTest, Can_Convert_hectare_to_sFoot) {
    Converter.SetValue(0.5);
    Converter.SetAreaType(hectare);
    EXPECT_EQ(53821.3, Converter.ConvertToNewType(sFoot));
}

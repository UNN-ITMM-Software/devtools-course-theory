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

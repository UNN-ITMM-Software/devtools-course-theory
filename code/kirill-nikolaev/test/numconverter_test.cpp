// Copyright 2013 K.Nikolaev

#include <gtest/gtest.h>
#include <string>

#include "library/NumConverter.h"

TEST(NumConverterTest, conv_can_Convert_From_Bin_To_Dec) {
    NumConverter a(std::string("10101010101000001"), bin);
    EXPECT_EQ(std::string("87361"), a.ToDecimal());
}

TEST(NumConverterTest, conv_can_Convert_From_Bin_To_Oct) {
    NumConverter a(std::string("10101010101000001"), bin);
    EXPECT_EQ(std::string("252501"), a.ToOctal());
}

TEST(NumConverterTest, conv_can_Convert_From_Bin_To_Hex) {
    NumConverter a(std::string("10101010101000001"), bin);
    EXPECT_EQ(std::string("15541"), a.ToHex());
}

TEST(NumConverterTest, conv_can_Convert_From_Oct_To_Bin) {
    NumConverter a(std::string("252501"), oct);
    EXPECT_EQ(std::string("10101010101000001"), a.ToBinary());
}

TEST(NumConverterTest, conv_can_Convert_From_Oct_To_Dec) {
    NumConverter a(std::string("252501"), oct);
    EXPECT_EQ(std::string("87361"), a.ToDecimal());
}

TEST(NumConverterTest, conv_can_Convert_From_Oct_To_Hex) {
    NumConverter a(std::string("252501"), oct);
    EXPECT_EQ(std::string("15541"), a.ToHex());
}

TEST(NumConverterTest, conv_can_Convert_From_Dec_To_Bin) {
    NumConverter a(std::string("87361"), dec);
    EXPECT_EQ(std::string("10101010101000001"), a.ToBinary());
}

TEST(NumConverterTest, conv_can_Convert_From_Dec_To_Oct) {
    NumConverter a(std::string("87361"), dec);
    EXPECT_EQ(std::string("252501"), a.ToOctal());
}

TEST(NumConverterTest, conv_can_Convert_From_Dec_To_Hex) {
    NumConverter a(std::string("87361"), dec);
    EXPECT_EQ(std::string("15541"), a.ToHex());
}

TEST(NumConverterTest, conv_can_Convert_From_Hex_To_Bin) {
    NumConverter a(std::string("15541"), hex);
    EXPECT_EQ(std::string("10101010101000001"), a.ToBinary());
}

TEST(NumConverterTest, conv_can_Convert_From_Hex_To_Oct) {
    NumConverter a(std::string("15541"), hex);
    EXPECT_EQ(std::string("252501"), a.ToOctal());
}

TEST(NumConverterTest, conv_can_Convert_From_Hex_To_Dec) {
    NumConverter a(std::string("15541"), hex);
    EXPECT_EQ(std::string("87361"), a.ToDecimal());
}

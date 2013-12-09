/* Copyright 2013 Vasiliy Kumaev */

#include <gtest/gtest.h>

#include <string>

#include "library/currencyconvert_application.h"

using ::testing::internal::RE;

TEST(AppTest, Do_Print_Help_Without_Arguments) {
    // Arrange
    CurrencyConvertorApplication app;
    int argc = 1;
    const char* argv[] = {"appname"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("This is a currency convertor application")));
}


TEST(AppTest, Can_Detect_Wrong_Number_Format) {
    // Arrange
    CurrencyConvertorApplication app;
    int argc = 4;
    const char* argv[] = {"appname", "x", "Euro", "Ruble"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("Wrong format!")));
}

TEST(AppTest, Can_Detect_Wrong_Unit_Format) {
    // Arrange
    CurrencyConvertorApplication app;
    int argc = 4;
    const char* argv[] = {"appname", "100", "1", "Pound"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("Wrong format!")));
}

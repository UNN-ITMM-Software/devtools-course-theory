// Copyright 2013 Dmitry Vodopyanov

#include <gtest/gtest.h>

#include <string>

#include "library/LengthConvertorApp.h"

using ::testing::internal::RE;

TEST(AppTest, Do_Print_Help_Without_Arguments) {
    // Arrange
    LengthConvertorApp app;
    int argc = 1;
    const char* argv[] = {"appname"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("This is a length")));
}

TEST(AppTest, Is_Checking_Number_Of_Arguments) {
    // Arrange
    LengthConvertorApp app;
    int argc = 3;
    const char* argv[] = {"appname", "5", "km"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("ERROR: Should be 3 arguments\\..*")));
}

TEST(AppTest, Can_Detect_Wrong_Number_Format) {
    // Arrange
    LengthConvertorApp app;
    int argc = 4;
    const char* argv[] = {"appname", "1qwee", "in", "m"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("Wrong data format!")));
}

TEST(AppTest, Can_Detect_Wrong_Operation_Format) {
    // Arrange
    LengthConvertorApp app;
    int argc = 4;
    const char* argv[] = {"appname", "1", "km", "g"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("Wrong data format!")));
}

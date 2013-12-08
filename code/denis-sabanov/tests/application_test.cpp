// Copyright 2013 Denis Sabanov

#include <gtest/gtest.h>
#include <string>
#include "library/AreaConverterApp.h"

using ::testing::internal::RE;

TEST(AppTest, Do_Print_Help_Without_Arguments) {
    // Arrange
    AreaConverterApp app;
    int argc = 1;
    char* argv[] = {"appname"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("This is a weight convertor application")));
}

TEST(AppTest, Can_Detect_Wrong_Number_Format) {
    // Arrange
    AreaConverterApp app;
    int argc = 4;
    char* argv[] = {"appname", "x", "hectare", "ar"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("Wrong number format!")));
}

TEST(AppTest, Can_Detect_Wrong_Operation_Format) {
    // Arrange
    AreaConverterApp app;
    int argc = 4;
    char* argv[] = {"appname", "1", "1", "abc"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("Wrong number format!")));
}
// Copyright 2013 Kirill Kornyakov

#include <gtest/gtest.h>

#include <string>

#include "library/calc_application.h"

using ::testing::internal::RE;

TEST(AppTest, Do_Print_Help_Without_Arguments) {
    // Arrange
    CalculatorApplication app;
    int argc = 1;
    const char* argv[] = {"appname"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("This is a simple")));
}

TEST(AppTest, Is_Checking_Number_Of_Arguments) {
    // Arrange
    CalculatorApplication app;
    int argc = 3;
    const char* argv[] = {"appname", "1", "2"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("ERROR: Should be 3 arguments\\..*")));
}

TEST(AppTest, Can_Detect_Wrong_Number_Format) {
    // Arrange
    CalculatorApplication app;
    int argc = 4;
    const char* argv[] = {"appname", "1", "2werwe", "+"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("Wrong number format!")));
}

TEST(AppTest, Can_Detect_Wrong_Operation_Format) {
    // Arrange
    CalculatorApplication app;
    int argc = 4;
    const char* argv[] = {"appname", "1", "2", "g"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("Wrong operation!")));
}

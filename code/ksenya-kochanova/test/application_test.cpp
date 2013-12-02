/* Copyright 2013 Ksenya Kochanova */


#include <gtest/gtest.h>
#include <string>
#include "library/TempConv_application.h"

using ::testing::internal::RE;

TEST(AppTest, Do_Print_Help_Without_Arguments) {

    // Arrange
    TempConv app;
    int argc = 1;
    const char* argv[] = {"appname"};
    // Act
    std::string output = app(argc, argv);
    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("This is a temperature convertor")));
}

TEST(AppTest, Is_Checking_Number_Of_Arguments) {

    // Arrange
    TempConv app;
    int argc = 3;
    const char* argv[] = {"appname", "18", "Kelvin"};
    // Act
    std::string output = app(argc, argv);
    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("ERROR: Should be 3 arguments\\..*")));
}

TEST(AppTest, Can_Detect_Wrong_Value_Format) {

    // Arrange
    TempConv app;
    int argc = 4;
    const char* argv[] = {"appname", "two", "Newton", "Kelvin"};
    // Act
    std::string output = app(argc, argv);
    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("Wrong value format!")));
}

TEST(AppTest, Can_Detect_Wrong_Unit_Format) {
    // Arrange
    TempConv app;
    int argc = 4;
    const char* argv[] = {"appname", "10", "fff", "Celsius"};
    // Act
    std::string output = app(argc, argv);
    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("Wrong unit format!")));
}

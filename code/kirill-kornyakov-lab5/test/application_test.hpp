// Copyright 2013 Kirill Kornyakov

#include <string>
#include "library/calc_application.h"
#include "gtest/gtest.h"

using ::testing::internal::RE;

TEST(AppTest, Do_Print_Help_Without_Arguments) {
    // Arrange
    CalculatorApplication app;
    const char* args[] = {"appname"};
    int argc = 1;
    char** argv = const_cast<char**>(args);

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("This is a simple")));
}

TEST(AppTest, Is_Checking_Number_Of_Arguments) {
    CalculatorApplication app;
    const char* args[] = {"appname", "1", "2"};

    int argc = 3;
    char** argv = const_cast<char**>(args);
    std::string output = app(argc, argv);

    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("ERROR: Should be 3 arguments\\..*")));
}

TEST(AppTest, Can_Detect_Wrong_Number_Format) {
    // Arrange
    CalculatorApplication app;
    const char* args[] = {"appname", "1", "2werwe", "+"};
    int argc = 4;
    char** argv = const_cast<char**>(args);

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
    const char* args[] = {"appname", "1", "2", "g"};
    int argc = 4;
    char** argv = const_cast<char**>(args);

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("Wrong operation!")));
}

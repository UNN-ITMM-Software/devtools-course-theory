// Copyright 2013 Aleksey Nesmelov

#include <gtest/gtest.h>

#include <string>

#include "library/fractcalc_application.h"

using ::testing::internal::RE;

class AppTest : public ::testing::Test {
 protected:
    AppTest() : app(), output("") {}
    void RunAndCheck(int argc, const char* argv[], std::string expected) {
        // Act
        output = app(argc, argv);
        // Assert
        EXPECT_TRUE(RE::PartialMatch(output, RE(expected)));
    }

    FractionCalculatorApplication app;
    std::string output;
};

TEST(AppTest, can_Print_Help_Without_Arguments) {
    FractionCalculatorApplication app;
    int argc = 1;
    const char* argv[] = {"appname"};

    RunAndCheck(argc, argv, "This is a fraction");
}

TEST(AppTest, can_Check_Number_Of_Arguments) {
    FractionCalculatorApplication app;
    int argc = 5;
    const char* argv[] = {"appname", "5", "6", "8", "9"};

    RunAndCheck(argc, argv, "ERROR: Should be 5 arguments\\..*");
}

TEST(AppTest, can_Detect_Wrong_Number_Format) {
    FractionCalculatorApplication app;
    int argc = 6;
    const char* argv[] = {"appname", "2", "6", "7", "n", "-"};

    RunAndCheck(argc, argv, "Wrong number format!");
}

TEST(AppTest, can_Detect_Wrong_Operation_Format) {
    FractionCalculatorApplication app;
    int argc = 6;
    const char* argv[] = {"appname", "1", "7", "3", "8", "r"};

    RunAndCheck(argc, argv, "Wrong operation!");
}

TEST(AppTest, can_Add_Positive_Fractions) {
    FractionCalculatorApplication app;
    int argc = 6;
    const char* argv[] = {"appname", "1", "3", "1", "2", "+"};

    RunAndCheck(argc, argv, "Result = 5 / 6");
}

TEST(AppTest, can_Sub_Positive_Fractions) {
    FractionCalculatorApplication app;
    int argc = 6;
    const char* argv[] = {"appname", "1", "4", "3", "5", "-"};

    RunAndCheck(argc, argv, "Result = -7 / 20");
}

TEST(AppTest, can_Mult_Positive_Fractions) {
    FractionCalculatorApplication app;
    int argc = 6;
    const char* argv[] = {"appname", "2", "3", "3", "4", "*"};

    RunAndCheck(argc, argv, "Result = 1 / 2");
}

TEST(AppTest, can_Div_Positive_Fractions) {
    FractionCalculatorApplication app;
    int argc = 6;
    const char* argv[] = {"appname", "1", "3", "2", "3", "/"};

    RunAndCheck(argc, argv, "Result = 1 / 2");
}

TEST(AppTest, can_Add_Negative_Fractions) {
    FractionCalculatorApplication app;
    int argc = 6;
    const char* argv[] = {"appname", "-1", "3", "-1", "2", "+"};

    RunAndCheck(argc, argv, "Result = -5 / 6");
}

TEST(AppTest, can_Sub_Negative_Fractions) {
    FractionCalculatorApplication app;
    int argc = 6;
    const char* argv[] = {"appname", "-1", "4", "-3", "5", "-"};

    RunAndCheck(argc, argv, "Result = 7 / 20");
}

TEST(AppTest, can_Mult_Negative_Fractions) {
    FractionCalculatorApplication app;
    int argc = 6;
    const char* argv[] = {"appname", "-2", "3", "-3", "4", "*"};

    RunAndCheck(argc, argv, "Result = 1 / 2");
}

TEST(AppTest, can_Div_Negative_Fractions) {
    FractionCalculatorApplication app;
    int argc = 6;
    const char* argv[] = {"appname", "-1", "3", "-2", "3", "/"};

    RunAndCheck(argc, argv, "Result = 1 / 2");
}

TEST(AppTest, can_Enter_Fractions_With_Negative_Denominator) {
    FractionCalculatorApplication app;
    int argc = 6;
    const char* argv[] = {"appname", "1", "-3", "2", "-3", "*"};

    RunAndCheck(argc, argv, "Result = 2 / 9");
}

TEST(AppTest, can_not_Enter_Fractions_With_Zero_Denominator) {
    FractionCalculatorApplication app;
    int argc = 6;
    const char* argv[] = {"appname", "1", "0", "2", "-3", "*"};

    RunAndCheck(argc, argv, "Wrong denominator!");
}

TEST(AppTest, can_not_Div_Fractions_With_Zero_Divisor) {
    FractionCalculatorApplication app;
    int argc = 6;
    const char* argv[] = {"appname", "1", "2", "0", "1", "/"};

    RunAndCheck(argc, argv, "Wrong divisor!");
}

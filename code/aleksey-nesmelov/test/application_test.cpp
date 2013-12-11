// Copyright 2013 Aleksey Nesmelov

#include <gtest/gtest.h>

#include <string>

#include "library/fractcalc_application.h"

using ::testing::internal::RE;

class AppTest : public ::testing::Test {
 protected:
    AppTest() : app_(), output_("") {}

    void RunAndCheck(int argc, const char* argv[], std::string expected) {
        // Act
        output_ = app_(argc, argv);
        // Assert
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

    FractionCalculatorApplication app_;
    std::string output_;
};

TEST_F(AppTest, can_Print_Help_Without_Arguments) {
    int argc = 1;
    const char* argv[] = {"appname"};

    RunAndCheck(argc, argv, "This is a fraction");
}

TEST_F(AppTest, can_Check_Number_Of_Arguments) {
    int argc = 5;
    const char* argv[] = {"appname", "5", "6", "8", "9"};

    RunAndCheck(argc, argv, "ERROR: Should be 5 arguments\\..*");
}

TEST_F(AppTest, can_Detect_Wrong_Number_Format) {
    int argc = 6;
    const char* argv[] = {"appname", "2", "6", "7", "n", "-"};

    RunAndCheck(argc, argv, "Wrong number format!");
}

TEST_F(AppTest, can_Detect_Wrong_Operation_Format) {
    int argc = 6;
    const char* argv[] = {"appname", "1", "7", "3", "8", "r"};

    RunAndCheck(argc, argv, "Wrong operation!");
}

TEST_F(AppTest, can_Add_Positive_Fractions) {
    int argc = 6;
    const char* argv[] = {"appname", "1", "3", "1", "2", "+"};

    RunAndCheck(argc, argv, "Result = 5 / 6");
}

TEST_F(AppTest, can_Sub_Positive_Fractions) {
    int argc = 6;
    const char* argv[] = {"appname", "1", "4", "3", "5", "-"};

    RunAndCheck(argc, argv, "Result = -7 / 20");
}

TEST_F(AppTest, can_Mult_Positive_Fractions) {
    int argc = 6;
    const char* argv[] = {"appname", "2", "3", "3", "4", "*"};

    RunAndCheck(argc, argv, "Result = 1 / 2");
}

TEST_F(AppTest, can_Div_Positive_Fractions) {
    int argc = 6;
    const char* argv[] = {"appname", "1", "3", "2", "3", "/"};

    RunAndCheck(argc, argv, "Result = 1 / 2");
}

TEST_F(AppTest, can_Add_Negative_Fractions) {
    int argc = 6;
    const char* argv[] = {"appname", "-1", "3", "-1", "2", "+"};

    RunAndCheck(argc, argv, "Result = -5 / 6");
}

TEST_F(AppTest, can_Sub_Negative_Fractions) {
    int argc = 6;
    const char* argv[] = {"appname", "-1", "4", "-3", "5", "-"};

    RunAndCheck(argc, argv, "Result = 7 / 20");
}

TEST_F(AppTest, can_Mult_Negative_Fractions) {
    int argc = 6;
    const char* argv[] = {"appname", "-2", "3", "-3", "4", "*"};

    RunAndCheck(argc, argv, "Result = 1 / 2");
}

TEST_F(AppTest, can_Div_Negative_Fractions) {
    int argc = 6;
    const char* argv[] = {"appname", "-1", "3", "-2", "3", "/"};

    RunAndCheck(argc, argv, "Result = 1 / 2");
}

TEST_F(AppTest, can_Enter_Fractions_With_Negative_Denominator) {
    int argc = 6;
    const char* argv[] = {"appname", "1", "-3", "2", "-3", "*"};

    RunAndCheck(argc, argv, "Result = 2 / 9");
}

TEST_F(AppTest, can_not_Enter_Fractions_With_Zero_Denominator) {
    int argc = 6;
    const char* argv[] = {"appname", "1", "0", "2", "-3", "*"};

    RunAndCheck(argc, argv, "Wrong denominator!");
}

TEST_F(AppTest, can_not_Div_Fractions_With_Zero_Divisor) {
    int argc = 6;
    const char* argv[] = {"appname", "1", "2", "0", "1", "/"};

    RunAndCheck(argc, argv, "Wrong divisor!");
}

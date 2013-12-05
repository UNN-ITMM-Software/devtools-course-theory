/* Copyright 2013 Andrey Golodyaev */

#include <gtest/gtest.h>
#include <string>

#include "library/complexcalc_application.h"

using ::testing::internal::RE;

class AppTest : public ::testing::Test {
 protected:
    AppTest() : app_(), output_("") {}

    void RunAndCheck(int argc, const char* argv[], std::string expected) {
        output_ = app_(argc, argv);
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

    ComplexCalculatorApplication app_;
    std::string output_;
};

TEST_F(AppTest, calc_can_Print_Help_Without_Arguments) {
    int argc = 1;
    const char* argv[] = {"appname"};
    RunAndCheck(argc, argv, "This is a calculator of complex numbers\\..*");
}

TEST_F(AppTest, calc_can_Check_Number_Of_Arguments) {
    int argc = 3;
    const char* argv[] = {"appname", "1+i", "i"};
    RunAndCheck(argc, argv, "ERROR: Should be 3 arguments\\..*");
}

TEST_F(AppTest, calc_can_Detect_Wrong_Number_Format) {
    int argc = 4;
    const char* argv[] = {"appname", "1+iu", "i", "+"};
    RunAndCheck(argc, argv, "Wrong number format!.*");
}

TEST_F(AppTest, calc_can_Detect_Wrong_Operation_Format) {
    int argc = 4;
    const char* argv[] = {"appname", "1+i", "i", "b"};
    RunAndCheck(argc, argv, "Wrong operation!.*");
}

TEST_F(AppTest, calc_can_Add_Numbers1) {
    int argc = 4;
    const char* argv[] = {"appname", "1+2*i", "2-3i", "+"};
    RunAndCheck(argc, argv, "[A+B = 3-i]");
}

TEST_F(AppTest, calc_can_Add_Numbers2) {
    int argc = 4;
    const char* argv[] = {"appname", "1+i2", "2-i*3", "+"};
    RunAndCheck(argc, argv, "[A+B = 3-i]");
}

TEST_F(AppTest, calc_can_Add_Numbers3) {
    int argc = 4;
    const char* argv[] = {"appname", "-2*i+1", "i3+2", "+"};
    RunAndCheck(argc, argv, "[A+B = 3+i]");
}

TEST_F(AppTest, calc_can_Sub_Numbers) {
    int argc = 4;
    const char* argv[] = {"appname", "i", "1-i", "-"};
    RunAndCheck(argc, argv, "[A-B = -1+2*i]");
}

TEST_F(AppTest, calc_can_Mul_Numbers) {
    int argc = 4;
    const char* argv[] = {"appname", "1+i", "1+i", "*"};
    RunAndCheck(argc, argv, "[A*B = 2*i]");
}

TEST_F(AppTest, calc_can_Div_Numbers) {
    int argc = 4;
    const char* argv[] = {"appname", "1+i", "i", "/"};
    RunAndCheck(argc, argv, "[A/B = 1-i]");
}

TEST_F(AppTest, calc_can_not_Div_by_Zero) {
    int argc = 4;
    const char* argv[] = {"appname", "1+i", "0", "/"};
    RunAndCheck(argc, argv, "division by zero");
}


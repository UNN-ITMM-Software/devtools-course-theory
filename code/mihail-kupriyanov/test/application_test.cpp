// Copyright 2013 Michail Kupriyanov

#include <gtest/gtest.h>

#include <string>

#include "library/mathquancalc_application.h"

using ::testing::internal::RE;

class AppTest : public ::testing::Test {
 protected:
    void RunApp(int argc, const char* argv[]) {
        output_ = app_(argc, argv);
    }

    void Check(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

    MathQuanCalcApplication app_;
    std::string output_;
};

TEST_F(AppTest, Do_Print_Help_Without_Arguments) {
    int argc = 1;
    const char* argv[] = {"appname"};

    RunApp(argc, argv);

    Check("This is a math quantities calculator application\\..*");
}

TEST_F(AppTest, Is_Checking_Number_Of_Arguments) {
    int argc = 4;
    const char* argv[] = {"appname",  "1", "0.5", "2"};

    RunApp(argc, argv);

    Check("ERROR: wrong arguments format\\..*");
}

TEST_F(AppTest, Can_Detect_Wrong_Number_Format) {
    int argc = 5;
    const char* argv[] = {"appname", "1", "as", "2", "0.5"};

    RunApp(argc, argv);

    Check("ERROR: wrong number format.*");
}

TEST_F(AppTest, Can_Calc_ExpValue_And_Dispersion) {
    int argc = 9;
    const char* argv[] = {"appname", "1", "0.15", "2",
        "0.25", "3", "0.2", "4", "0.4"};

    RunApp(argc, argv);

    Check("Result: \nExpected value:  2.85\nDispersion:  1.2275\n");
}

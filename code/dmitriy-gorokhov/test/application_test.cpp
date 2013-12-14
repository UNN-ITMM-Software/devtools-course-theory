/* Copyright 2013 Dmitriy Gorokhov */

#include <gtest/gtest.h>

#include <string>

#include "library/QuadraticEquationApplication.h"

using ::testing::internal::RE;

class AppTest : public ::testing::Test {
 protected:
    void RunApp(int argc, const char* argv[]) {
        output_ = app_(argc, argv);
    }

    void Check(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

    QuadraticEquationApplication app_;
    std::string output_;
};

TEST_F(AppTest, Can_Print_Help_Without_Arguments) {
    int argc = 1;
    const char* argv[] = {"appname"};

    RunApp(argc, argv);

    Check("This is a quadratic.*");
}

TEST_F(AppTest, can_Check_Number_Of_Arguments) {
    int argc = 3;
    const char* argv[] = {"appname", "1", "2"};

    RunApp(argc, argv);

    Check("ERROR: Should be 3 coefficients!.*");
}

TEST_F(AppTest, can_Detect_Wrong_Number_Format) {
    int argc = 4;
    const char* argv[] = {"appname", "1", "2", "eps"};

    RunApp(argc, argv);

    Check("Wrong coefficients format!.*");
}

TEST_F(AppTest, can_Detect_Zero_First_Coefficient) {
    int argc = 4;
    const char* argv[] = {"appname", "0", "7.5", "5.0"};

    RunApp(argc, argv);

    Check("First coefficient must be non-zero!.*");
}

TEST_F(AppTest, can_Solve_Equation_With_Integer_Coefficients) {
    int argc = 4;
    const char* argv[] = {"appname", "1", "2", "-3"};

    RunApp(argc, argv);

    Check("Result = Root1 = 1, Root2 = -3.*");
}

TEST_F(AppTest, can_Solve_Equation_With_Real_Coefficients) {
    int argc = 4;
    const char* argv[] = {"appname", "1.7", "6.95", "-2.3"};

    RunApp(argc, argv);

    Check("Result = Root1 = 0\\.307766, Root2 = -4\\.396.*");
}

TEST_F(AppTest, can_Solve_Equation_With_Zero_Third_Coefficient) {
    int argc = 4;
    const char* argv[] = {"appname", "1", "8", "0"};

    RunApp(argc, argv);

    Check("Result = Root1 = 0, Root2 = -8.*");
}

TEST_F(AppTest, can_Solve_Equation_With_One_Real_Root) {
    int argc = 4;
    const char* argv[] = {"appname", "1", "2", "1"};

    RunApp(argc, argv);

    Check("Result = Root1 = -1, Root2 = -1.*");
}

TEST_F(AppTest, can_Detect_Equation_With_No_Real_Roots) {
    int argc = 4;
    const char* argv[] = {"appname", "1", "0", "4"};

    RunApp(argc, argv);

    Check("Result = No real roots.*");
}

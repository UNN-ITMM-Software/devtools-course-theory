/* Copyright 2013 Ksenya Kochanova */

#include <gtest/gtest.h>

#include <string>

#include "library/TempConv_application.h"

using ::testing::internal::RE;

class AppTestR : public ::testing::Test {
 protected:
    // NOTE: here you can put your init/deinit code
    // virtual void SetUp() {}
    // virtual void TearDown() {}

    void RunApp(int argc, const char* argv[]) {
        output_ = app_(argc, argv);
    }

    void Check(std::string expected) {
        // printf("OUTPUT = %s\n", output_.c_str());
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

    CalculatorApplication app_;
    std::string output_;
};

TEST_F(AppTestR, can_Print_Help_Without_Arguments) {
    int argc = 1;
    const char* argv[] = {"appname"};

    RunApp(argc, argv);

    Check("This is a temperature convertor application\\..*");
}

TEST_F(AppTestR, can_Check_Number_Of_Arguments) {
    int argc = 3;
    const char* argv[] = {"appname", "10", "Kelvin"};

    RunApp(argc, argv);

    Check("ERROR: Should be 3 arguments: value, oldunit, newunit\\..*");
}

TEST_F(AppTestR, can_Detect_Wrong_Value_Format_for_Celsius) {
    int argc = 4;
    const char* argv[] = {"appname", "-300", "Celsius", "Kelvin"};

    RunApp(argc, argv);

    Check("Wrong data!.*");
}

TEST_F(AppTestR, can_Detect_Wrong_Value_Format_for_Kelvin) {
    int argc = 4;
    const char* argv[] = {"appname", "-10", "Kelvin", "Newton"};

    RunApp(argc, argv);

    Check("Wrong data!.*");
}

TEST_F(AppTestR, can_Detect_Wrong_Value_Format_for_Newton) {
    int argc = 4;
    const char* argv[] = {"appname", "-100", "Newton", "Kelvin"};

    RunApp(argc, argv);

    Check("Wrong data!.*");
}

TEST_F(AppTestR, can_Detect_Wrong_Value_Format_for_Fahrenheit) {
    int argc = 4;
    const char* argv[] = {"appname", "-500", "Celsius", "Kelvin"};

    RunApp(argc, argv);

    Check("Wrong data!.*");
}
TEST_F(AppTestR, can_Detect_Wrong_oldUnit_Format) {
    int argc = 4;
    const char* argv[] = {"appname", "10", "jjj", "Kelvin"};

    RunApp(argc, argv);

    Check("Wrong format!");
}

TEST_F(AppTestR, can_Detect_Wrong_newUnit_Format) {
    int argc = 4;
    const char* argv[] = {"appname", "10", "Newton", "iii"};

    RunApp(argc, argv);

    Check("Wrong format!");
}

TEST_F(AppTestR, can_Convert_Correct_Value_Kelvin_to_Celsius) {
    int argc = 4;
    const char* argv[] = {"appname", "0", "Kelvin", "Celsius"};

    RunApp(argc, argv);

    Check("Result = -273.150000");
}

TEST_F(AppTestR, can_Convert_Correct_Value_Celsius_Newton) {
    int argc = 4;
    const char* argv[] = {"appname", "0", "Celsius", "Newton"};

    RunApp(argc, argv);

    Check("Result = 1.650000");
}

TEST_F(AppTestR, can_Convert_Correct_Value_Fahrenheit_Celsius) {
    int argc = 4;
    const char* argv[] = {"appname", "0", "Fahrenheit", "Celsius"};

    RunApp(argc, argv);

    Check("Result = -26.444444");
}

TEST_F(AppTestR, can_Convert_Correct_Value_Newton_Fahrenheit) {
    int argc = 4;
    const char* argv[] = {"appname", "0", "Newton", "Fahrenheit"};

    RunApp(argc, argv);

    Check("Result = 57.600000");
}

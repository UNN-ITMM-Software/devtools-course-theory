/* Copyright 2013 Vasiliy Kumaev */

#include <gtest/gtest.h>

#include <string>

#include "library/currencyconvert_application.h"

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

    CurrencyConvertorApplication app_;
    std::string output_;
};

TEST_F(AppTestR, Do_Print_Help_Without_Arguments) {
    int argc = 1;
    const char* argv[] = {"appname"};

    RunApp(argc, argv);

    Check("This is a currency convertor application");
}

TEST_F(AppTestR, Can_Check_Number_Of_Arguments) {
    int argc = 3;
    const char* argv[] = {"appname", "23", "Dollar"};

    RunApp(argc, argv);

    Check("ERROR: Should be 3 arguments\\..*");
}

TEST_F(AppTestR, Can_Detect_Wrong_Negative_Value) {
    int argc = 4;
    const char* argv[] = {"appname", "-100", "Dollar", "Pound"};

    RunApp(argc, argv);

    Check("Result = -1");
}

TEST_F(AppTestR, Can_Detect_Wrong_UnitInput_Format) {
    int argc = 4;
    const char* argv[] = {"appname", "10", "piw", "Pound"};

    RunApp(argc, argv);

    Check("Wrong format!");
}

TEST_F(AppTestR, Can_Detect_Wrong_UnitOutput_Format) {
    int argc = 4;
    const char* argv[] = {"appname", "100", "Dollar", "sum41"};

    RunApp(argc, argv);

    Check("Wrong format!");
}

TEST_F(AppTestR, Can_Convert_Euro_toDollar) {
    int argc = 4;
    const char* argv[] = {"appname", "100", "Euro", "Dollar"};

    RunApp(argc, argv);

    Check("Result = 74");
}

TEST_F(AppTestR, Can_Convert_Ruble_to_Dollar) {
    int argc = 4;
    const char* argv[] = {"appname", "100", "Ruble", "Dollar"};

    RunApp(argc, argv);

    Check("Result = 3");
}

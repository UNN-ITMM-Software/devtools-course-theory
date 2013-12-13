// Copyright 2013 Pavel Korotaev

#include <gtest/gtest.h>

#include <string>

#include "library/weightconvertor_application.h"

using ::testing::internal::RE;

class AppTestR : public ::testing::Test {
 protected:
    void RunApp(int argc, const char* argv[]) {
        output_ = app_(argc, argv);
    }


    void Check(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

    WeightConvertorApplication app_;
    std::string output_;
};

TEST_F(AppTestR, Do_Print_Help_Without_Arguments) {
    int argc = 1;
    const char* argv[] = {"appname"};

    RunApp(argc, argv);

    Check("This is a weight convertor application");
}

TEST_F(AppTestR, Can_Detect_Wrong_UnitInput_Format) {
    int argc = 4;
    const char* argv[] = {"appname", "20", "qw", "Stone"};

    RunApp(argc, argv);

    Check("Wrong number format!");
}

TEST_F(AppTestR, Can_Detect_Wrong_UnitOutput_Format) {
    int argc = 4;
    const char* argv[] = {"appname", "20", "Stone", "we"};

    RunApp(argc, argv);

    Check("Wrong number format!");
}

TEST_F(AppTestR, Can_Convert_Ton_to_Hundredweight) {
    int argc = 4;
    const char* argv[] = {"appname", "2.5", "Ton", "Hundredweight"};

    RunApp(argc, argv);

    Check("Result = 25");
}

TEST_F(AppTestR, Can_Convert_Pound_to_Stone) {
    int argc = 4;
    const char* argv[] = {"appname", "100", "Pound", "Stone"};

    RunApp(argc, argv);

    Check("Result = 7.142");
}

TEST_F(AppTestR, Can_Convert_Grams_to_Kilograms) {
    int argc = 4;
    const char* argv[] = {"appname", "4000", "Grams", "Kilograms"};

    RunApp(argc, argv);

    Check("Result = 4");
}

TEST_F(AppTestR, Can_Convert_Ounce_to_Hundredweight) {
    int argc = 4;
    const char* argv[] = {"appname", "156", "Ounce", "Hundredweight"};

    RunApp(argc, argv);

    Check("Result = 0.044");
}

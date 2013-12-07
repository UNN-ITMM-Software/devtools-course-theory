// Copyright 2013 Dmitry Vodopyanov

#include <gtest/gtest.h>

#include <string>

#include "library/LengthConvertorApp.h"

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

    LengthConvertorApp app_;
    std::string output_;
};

TEST_F(AppTestR, Do_Print_Help_Without_Arguments) {
    int argc = 1;
    const char* argv[] = {"appname"};

    RunApp(argc, argv);

    Check("This is a length");
}

TEST_F(AppTestR, Is_Checking_Number_Of_Arguments) {
    int argc = 3;
    const char* argv[] = {"appname",  "1", "in"};

    RunApp(argc, argv);

    Check("ERROR: Should be 3");
}

TEST_F(AppTestR, Can_Detect_Wrong_Unit_Format) {
    int argc = 4;
    const char* argv[] = {"appname", "1", "kkk", "m"};

    RunApp(argc, argv);

    Check("Wrong data format!");
}

TEST_F(AppTestR, Can_Convert_Yard_To_Inch) {
    int argc = 4;
    const char* argv[] = {"appname", "5", "yd", "in"};

    RunApp(argc, argv);

    Check("Result = 180");
}

// Copyright 2013 Denis Sabanov

#include <gtest/gtest.h>
#include <string>
#include "library/AreaConverterApp.h"

using ::testing::internal::RE;

class AppTest : public ::testing::Test {
 protected:

    void RunApp(int argc, const char* argv[]) {
        output_ = app_(argc, argv);
    }


    void Check(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

    AreaConverterApp app_;
    std::string output_;
};

TEST_F(AppTest, Do_Print_Help_Without_Arguments) {
    int argc = 1;
    const char* argv[] = {"appname"};

    RunApp(argc, argv);

    Check("This is a area convertor application");
}

TEST_F(AppTest, can_Check_Number_Of_Arguments) {
    int argc = 3;
    const char* argv[] = {"appname", "10", "ar"};

    RunApp(argc, argv);

    Check("ERROR: Should be 3 arguments\\..*");
}

TEST(AppTest, Can_Detect_Wrong_Number_Format) {
    int argc = 4;
    char* argv[] = {"appname", "s", "hectare", "ar"};

    RunApp(argc, argv);

    Check("Wrong number format!");
}

TEST(AppTest, Can_Detect_Wrong_Operation_Format) {
    int argc = 4;
    char* argv[] = {"appname", "1", "2", "qwe"};

    RunApp(argc, argv);

    Check("Wrong number format!");
}


TEST_F(AppTest, Can_Detect_Wrong_curUnit_Format) {
    int argc = 4;
    const char* argv[] = {"appname", "1,5", "qw", "sKilometer"};

    RunApp(argc, argv);

    Check("Wrong number format!");
}

TEST_F(AppTest, Can_Detect_Wrong_newUnit_Format) {
    int argc = 4;
    const char* argv[] = {"appname", "20", "sMeter", "we"};

    RunApp(argc, argv);

    Check("Wrong number format!");
}

TEST_F(AppTest, Can_Convert_sMeter_to_ar) {
    int argc = 4;
    const char* argv[] = {"appname", "100", "sMeter", "ar"};

    RunApp(argc, argv);

    Check("Result = 1");
}

TEST_F(AppTest, Can_Convert_sFoot_to_sMeter) {
    int argc = 4;
    const char* argv[] = {"appname", "100", "sFoot", "sMeter"};

    RunApp(argc, argv);

    Check("Result = 9.29");
}

TEST_F(AppTest, Can_Convert_sKilometer_to_acre) {
    int argc = 4;
    const char* argv[] = {"appname", "1.5", "sKilometer", "acre"};

    RunApp(argc, argv);

    Check("Result = 370.645");
}

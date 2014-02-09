// Copyright 2013 K.Nikolaev

#include <gtest/gtest.h>
#include <string>

#include "library/NumConverter_application.h"

using ::testing::internal::RE;

class AppTest : public ::testing::Test {
    protected:
        void RunApp(int argc, const char* argv[]) {
            output_ = app_(argc, argv);
        }
        void Check(std::string expected) {
            EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
        }
        NumConverterApplication app_;
        std::string output_;
};

TEST_F(AppTest, can_Print_Help) {
    int argc = 1;
    const char* argv[] = {"appname"};
    RunApp(argc, argv);

    Check("This is a number converter application.*");
}

TEST_F(AppTest, can_Check_Number_Of_Args) {
    int argc = 2;
    const char* argv[] = {"appname", "bin"};
    RunApp(argc, argv);

    Check("Error: Should be 2 arguments.");
}

TEST_F(AppTest, can_Detect_Wrong_Number_Format) {
    int argc = 3;
    const char* argv[] = {"appname", "bic", "10"};
    RunApp(argc, argv);

    Check("Error: Wrong name for a number system.");
}

TEST_F(AppTest, can_Detect_Wrong_Bin_Format) {
    int argc = 3;
    const char* argv[] = {"appname", "bin", "345"};
    RunApp(argc, argv);

    Check("Error: Wrong number format.");
}

TEST_F(AppTest, can_Detect_Wrong_Oct_Format) {
    int argc = 3;
    const char* argv[] = {"appname", "oct", "88027"};
    RunApp(argc, argv);

    Check("Error: Wrong number format.");
}

TEST_F(AppTest, can_Detect_Wrong_Dec_Format) {
    int argc = 3;
    const char* argv[] = {"appname", "dec", "b9c3f"};
    RunApp(argc, argv);

    Check("Error: Wrong number format.");
}


TEST_F(AppTest, can_Detect_Wrong_Hex_Format) {
    int argc = 3;
    const char* argv[] = {"appname", "hex", "hf"};
    RunApp(argc, argv);

    Check("Error: Wrong number format.");
}

TEST_F(AppTest, can_Detect_Large_Oct_Numbers) {
    int argc = 3;
    const char* argv[] = {"appname", "oct", "77777777771"};
    RunApp(argc, argv);

    Check("Error: Wrong number format.");
}

TEST_F(AppTest, can_Detect_Large_Bin_Numbers) {
    int argc = 3;
    const char* argv[] = {"appname", "bin",
    "11111111111111111111111111111110"};
    RunApp(argc, argv);

    Check("Error: Wrong number format.");
}

TEST_F(AppTest, can_Detect_Large_Dec_Numbers) {
    int argc = 3;
    const char* argv[] = {"appname", "dec", "9999999992"};
    RunApp(argc, argv);

    Check("Error: Wrong number format.");
}

TEST_F(AppTest, can_Detect_Large_Hex_Numbers) {
    int argc = 3;
    const char* argv[] = {"appname", "hex", "fffffff0"};
    RunApp(argc, argv);

    Check("Error: Wrong number format.");
}

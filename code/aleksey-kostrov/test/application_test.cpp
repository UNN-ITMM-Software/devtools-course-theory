/* Copyright 2013 Aleksey Kostrov */

#include <gtest/gtest.h>

#include <string>

#include "library/Dichotomy_Search_application.h"

using ::testing::internal::RE;

class AppTest : public ::testing::Test {
 protected:
    void RunApp(int argc, const char* argv[]) {
        output_ = app_(argc, argv);
    }

    void Check(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

    DichotomySearchApplication app_;
    std::string output_;
};


TEST_F(AppTest, Can_Print_Help_Without_Arguments) {
    int argc = 1;
    const char* argv[] = {"appname"};

    RunApp(argc, argv);

    Check("This is a dichotomy search application.*");
}

TEST_F(AppTest, Can_Check_Number_Of_Arguments) {
    int argc = 2;
    const char* argv[] = {"appname", "4"};

    RunApp(argc, argv);

    Check("ERROR: Should be 2 arguments!.*");
}

TEST_F(AppTest, Can_Detect_Wrong_Number_Format) {
    int argc = 3;
    const char* argv[] = {"appname", "10", "er"};

    RunApp(argc, argv);

    Check("Wrong arguments format!.*");
}

TEST_F(AppTest, Can_Detect_Incorrect_First_Argument) {
    int argc = 3;
    const char* argv[] = {"appname", "-1", "5"};

    RunApp(argc, argv);

    Check("Size of array must be more than zero!.*");
}

TEST_F(AppTest, Can_Detect_Not_Found_Element) {
    int argc = 3;
    const char* argv[] = {"appname", "10", "-5"};

    RunApp(argc, argv);

    Check("Element not found!.*");
}

TEST_F(AppTest, Can_Detect_Element) {
    int argc = 3;
    const char* argv[] = {"appname", "20", "54"};

    RunApp(argc, argv);

    Check("Index of search element: 1.*");
}

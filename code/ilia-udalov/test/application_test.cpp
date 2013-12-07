// Copyright 2013 Ilia Udalov

#include <gtest/gtest.h>

#include <string>

#include "library/regex_application.h"

using ::testing::internal::RE;

class AppTest : public ::testing::Test {
 protected:
    void RunApp(int argc, const char* argv[]) {
        output_ = app_(argc, argv);
    }

    void Check(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

    RegexApplication app_;
    std::string output_;
};

TEST_F(AppTest, Do_Print_Help_Without_Arguments) {
    int argc = 1;
    const char* argv[] = {"appname"};

    RunApp(argc, argv);

    Check("This is a simple handler for regexps and substrings\\..*");
}

TEST_F(AppTest, Is_Checking_Number_Of_Arguments) {
    int argc = 13;
    const char* argv[] = {"appname",  "banana", "banana", "banana", "banana"
        , "banana", "banana", "banana", "banana", "banana", "banana", "banana"};

    RunApp(argc, argv);

    Check("ERROR: Wrong number of arguments!.*");
}


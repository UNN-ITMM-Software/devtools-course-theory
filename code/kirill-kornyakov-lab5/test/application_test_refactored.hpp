// Copyright 2013 Kirill Kornyakov

#include <string>
#include "library/calc_application.h"
#include "gtest/gtest.h"

using ::testing::internal::RE;

class AppTestR : public ::testing::Test {
 protected:
    // NOTE: here you can put your init/deinit code
    // virtual void SetUp() {}
    // virtual void TearDown() {}

    void RunApp(int argc, const char* args[]) {
        char** argv = const_cast<char**>(args);
        output_ = app(argc, argv);
    }

    void Check(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(
                        output_,
                        RE(expected)));
    }

    CalculatorApplication app;
    std::string output_;
};

TEST_F(AppTestR, Do_Print_Help_Without_Arguments) {
    int argc = 1;
    const char* argv[] = {"appname"};

    RunApp(argc, argv);

    Check("This is a simple calculator application\\..*");
}

TEST_F(AppTestR, Is_Checking_Number_Of_Arguments) {
    int argc = 3;
    const char* argv[] = {"appname",  "1", "2"};

    RunApp(argc, argv);

    Check("ERROR: Should be 3 arguments\\..*");
}

TEST_F(AppTestR, Can_Detect_Wrong_Number_Format) {
    int argc = 4;
    const char* argv[] = {"appname", "1", "pi", "+"};

    RunApp(argc, argv);

    Check("Wrong number format!.*");
}

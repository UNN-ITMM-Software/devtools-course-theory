// Copyright 2013 Moshkov Yuriy

#include <gtest/gtest.h>

#include <string>

#include "library/DistApplication.h"

using ::testing::internal::RE;

class AppTest : public ::testing::Test {
 protected:
    void RunApp(int argc, const char* argv[]) {
        output_ = app_(argc, argv);
    }

    void Check(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

    DistApplication app_;
    std::string output_;
};

TEST_F(AppTest, Do_Print_Help_Without_Arguments) {
    int argc = 1;
    const char* argv[] = {"appname"};

    RunApp(argc, argv);

    Check("This is an application.*");
}

TEST_F(AppTest, Is_Checking_Number_Of_Arguments) {
    int argc = 3;
    const char* argv[] = {"appname", "2", "{1,0}"};

    RunApp(argc, argv);

    Check("ERROR: Should be 4 arguments.*");
}

TEST_F(AppTest, Can_Detect_Wrong_Vector_Format) {
    int argc = 5;
    const char* argv[] = {"appname", "3", "{3,4,1}", "4,3,2", "L1"};

    RunApp(argc, argv);

    Check("Wrong vector's format!.*");
}

TEST_F(AppTest, Can_Detect_Wrong_Number_Format_Size_Vector) {
    int argc = 5;
    const char* argv[] = {"appname", "a", "{1.1,2.1}", "{2.1,1}", "L2"};

    RunApp(argc, argv);

    Check("Wrong number format of size vector!");
}

TEST_F(AppTest, Can_Detect_Wrong_Number_Format_Vector_Elements) {
    int argc = 5;
    const char* argv[] = {"appname", "2", "{1.a,2.1}", "{2.1,1}", "L2"};

    RunApp(argc, argv);

    Check("Wrong number format of vector's elements!");
}

TEST_F(AppTest, Can_Detect_Wrong_Input_Size_Vector) {
    int argc = 5;
    const char* argv[] = {"appname", "-1", "{1.2,2.1}", "{2.1,1}", "L2"};

    RunApp(argc, argv);

    Check("Wrong input size vector!");
}

TEST_F(AppTest, Can_Detect_Wrong_Format_Type_Metric) {
    int argc = 5;
    const char* argv[] = {"appname", "3", "{1.2,2.1,3}", "{4,5.1,1}", "a"};

    RunApp(argc, argv);

    Check("Wrong format of type metric!");
}

TEST_F(AppTest, Can_Calculate_Distance_In_L1) {
    int argc = 5;
    const char* argv[] = {"appname", "3", "{1.2,2.1,3}", "{4,5.1,1}", "L1"};

    RunApp(argc, argv);

    Check("distance = 7\\.8");
}

TEST_F(AppTest, can_Calculate_Distance_In_L2) {
    int argc = 5;
    const char* argv[] = {"appname", "4", "{3.1,10.2,9.83,8.8}",
                          "{3.11,1.2,0.9,9.1}", "L2"};

    RunApp(argc, argv);

    Check("distance = 12\\.6821");
}

TEST_F(AppTest, can_Calculate_Distance_In_L3) {
    int argc = 5;
    const char* argv[] = {"appname", "5", "{31,102,98.3,1.4,2.4}",
                          "{31.1,12,1.03,3.05,5}", "L3"};

    RunApp(argc, argv);

    Check("distance = 118\\.151");
}

TEST_F(AppTest, can_Calculate_Large_Distance_In_L4) {
    int argc = 5;
    const char* argv[] = {"appname", "3", "{200000,20001.22222,1000000.1}",
                          "{120001.03,300000.05,500000}", "L4"};

    RunApp(argc, argv);

    Check("distance = 511940.*");
}

TEST_F(AppTest, can_Calculate_Distance_In_LInfinity) {
    int argc = 5;
    const char* argv[] = {"appname", "2", "{20000,10000.108}",
                          "{300000.05,50000}", "LInfinity"};

    RunApp(argc, argv);

    Check("distance = 280000.*");
}

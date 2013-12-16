/* Copyright 2013 Alexandr Smirnov */

#include <gtest/gtest.h>

#include <string>

#include "library/sort_application.h"

using ::testing::internal::RE;

class AppTestR : public ::testing::Test {
 protected:
    void RunApp(int argc, const char* argv[]) {
        output_ = app_(argc, argv);
    }

    void Check(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

    SorterApplication app_;
    std::string output_;
};

TEST_F(AppTestR, Do_Print_Help_Without_Arguments) {
    int argc = 1;
    const char* argv[] = {"appname"};

    RunApp(argc, argv);

    Check("This is an application of sorting arrays\\..*");
}

TEST_F(AppTestR, Is_Checking_Number_Of_Arguments) {
    int argc = 5;
    const char* argv[] = {"appname",  "m", "3", "7", "2"};

    RunApp(argc, argv);

    Check("ERROR: The number of arguments must\\..*");
}

TEST_F(AppTestR, Can_Detect_Wrong_Number_Format) {
    int argc = 5;
    const char* argv[] = {"appname", "q", "2", "r", "4"};

    RunApp(argc, argv);

    Check("Wrong number format!.*");
}

TEST_F(AppTestR, Can_Sort_Positive_Numbers_By_MergeSort) {
    int argc = 6;
    const char* argv[] = {"appname", "m", "3", "2", "1", "4"};

    RunApp(argc, argv);

    Check("Result of sorting: 1 2 4");
}

TEST_F(AppTestR, Can_Sort_Numbers_By_QuickSort) {
    int argc = 6;
    const char* argv[] = {"appname", "q", "3", "-7", "3", "-10"};

    RunApp(argc, argv);

    Check("Result of sorting: -10 -7 3");
}

TEST_F(AppTestR, Can_Sort_Large_Numbers_By_HeapSort) {
    int argc = 5;
    const char* argv[] = {"appname", "h", "2", "-10000000", "-50000000"};

    RunApp(argc, argv);

    Check("Result of sorting: -50000000 -10000000");
}

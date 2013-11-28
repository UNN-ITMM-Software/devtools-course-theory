/* Copyright 2013 Anna Zhbanova */

#include <string>
#include "library/Triangle_application.h"
#include <gtest/gtest.h>

#include <conio.h>
using ::testing::internal::RE;

class AppTestR : public ::testing::Test {
 protected:

    void RunApp(int argc, const char* argv[]) {
        output_ = app_(argc, argv);
    }

    void Check(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(
                        output_,
                        RE(expected)));
    }

    TriangleApplication app_;
    std::string output_;
};

TEST_F(AppTestR, Do_Print_Help_Without_Arguments) {
    int argc = 1;
    const char* argv[] = {"appname"};

    RunApp(argc, argv);

    Check("This is an application.*");
}

TEST_F(AppTestR, Can_Check_Number_Of_Arguments) {
    int argc = 3;
    const char* argv[] = {"appname",  "1", "2"};

    RunApp(argc, argv);

    Check("ERROR: Should be 4, 7, 8 or 9 arguments.*");
}

TEST_F(AppTestR, Can_Detect_Wrong_Number_Format) {
    int argc = 5;
    const char* argv[] = {"appname", "1", "1,1", "A", "0"};

    RunApp(argc, argv);

    Check("Wrong number format!.*");
}

TEST_F(AppTestR, Can_Detect_Wrong_Operation_Format) {
    int argc = 5;
    const char* argv[] = {"appname", "1", "1", "A", "+trash"};

    RunApp(argc, argv);

    Check("Wrong operation format!.*");
}

TEST_F(AppTestR, Can_Detect_Wrong_Name_Of_Vertex) {
    int argc = 5;
    const char* argv[] = {"appname", "1", "1", "z", "0"};

    RunApp(argc, argv);

    Check("Wrong name of vertex!.*");
}

TEST_F(AppTestR, Can_Detect_Wrong_Operation) {
    int argc = 5;
    const char* argv[] = {"appname", "1", "1", "A", "1"};

    RunApp(argc, argv);

    Check("- Wrong operation!.*");
}

TEST_F(AppTestR, Can_Set_Positive_Numbers) {
    int argc = 5;
    const char* argv[] = {"appname", "2", "3", "A", "0"};

    RunApp(argc, argv);

    Check("Result A = \\(2, 3\\)");
}

TEST_F(AppTestR, Can_Get_Positive_Numbers) {
    int argc = 9;
    const char* argv[] = {"appname", "1", "1", "2", "2", "6", "6",
                          "B", "1"};

    RunApp(argc, argv);

    Check("Result B = \\(2, 2\\).*");
}

TEST_F(AppTestR, Can_Set_Negative_Numbers) {
    int argc = 5;
    const char* argv[] = {"appname", "-20", "-30", "C", "0"};

    RunApp(argc, argv);

    Check("Result C = \\(-20, -30\\).*");
}

TEST_F(AppTestR, Can_Get_Negative_Numbers) {
    int argc = 9;
    const char* argv[] = {"appname", "-1", "-1", "-2.22", "-3.22",
                          "-0.2", "-0.3", "A", "1"};

    RunApp(argc, argv);

    Check("Result A = \\(-1, -1\\).*");
}

TEST_F(AppTestR, Can_Detect_Wrong_Triangle) {
    int argc = 8;
    const char* argv[] = {"appname", "0", "0", "5", "5", "2.5", "2.5", "4"};

    RunApp(argc, argv);

    Check("Result = Isn't correct.*");
}

TEST_F(AppTestR, Can_Detect_Correct_Triangle) {
    int argc = 8;
    const char* argv[] = {"appname", "0", "0", "5", "5", "0", "3", "4"};

    RunApp(argc, argv);

    Check("Result = Is correct.*");
}

TEST_F(AppTestR, Can_Detect_Equilateral_Triangle) {
    int argc = 8;
    const char* argv[] = {"appname", "0", "0", "3", "5", "5", "3", "5"};

    RunApp(argc, argv);

    Check("Result = Is equilateral.*");
}

TEST_F(AppTestR, Can_Detect_Not_Equilateral_Triangle) {
    int argc = 8;
    const char* argv[] = {"appname", "0", "0", "3", "7", "5", "3", "5"};

    RunApp(argc, argv);

    Check("Result = Isn't equilateral.*");
}

TEST_F(AppTestR, Can_Detect_Isosceles_Triangle) {
    int argc = 8;
    const char* argv[] = {"appname", "0", "0", "5", "0", "2.5",
                          "4.33012719", "6"};

    RunApp(argc, argv);

    Check("Result = Is isosceles.*");
}

TEST_F(AppTestR, Can_Detect_Not_Isosceles_Triangle) {
    int argc = 8;
    const char* argv[] = {"appname", "0", "0", "3", "7", "5", "3", "6"};

    RunApp(argc, argv);

    Check("Result = Isn't isosceles.*");
}

TEST_F(AppTestR, Can_Calculate_Side) {
    int argc = 10;
    const char* argv[] = {"appname", "0", "0", "3", "7", "5", "3",
                          "A", "B", "3"};

    RunApp(argc, argv);

    Check("Result Length AB = 7\\.62.*");
}

TEST_F(AppTestR, Can_Calculate_Angle) {
    int argc = 9;
    const char* argv[] = {"appname", "0", "0", "5", "0", "2.5",
                          "4.33012719", "A", "2"};

    RunApp(argc, argv);

    Check("Result Angle A = 60.*");
}

TEST_F(AppTestR, Can_Calculate_Square) {
    int argc = 8;
    const char* argv[] = {"appname", "0", "6", "3", "0", "0", "0", "7"};

    RunApp(argc, argv);

    Check("Result square = 9.*");
}

TEST_F(AppTestR, Can_Calculate_Perimeter) {
    int argc = 8;
    const char* argv[] = {"appname", "0", "3", "0", "0", "4", "0", "8"};

    RunApp(argc, argv);

    Check("Result perimeter = 12.*");
}

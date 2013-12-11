/* Copyright 2013 Anna Zhbanova */

#include <limits.h>
#include <math.h>
#include <string>
#include "gtest/gtest.h"
#include "library/Triangle.h"

class TriangleTest : public ::testing::Test {
 protected:
    Triangle triangle;
    TriangleTest() : triangle() {}
    void SetValue(float Ax, float Ay, float Bx, float By, float Cx, float Cy) {
        triangle = Triangle(PointXY(Ax, Ay), PointXY(Bx, By),
                            PointXY(Cx, Cy));
    }
};

TEST_F(TriangleTest, Can_Detect_Wrong_Triangle) {
    SetValue(0, 0, 5, 5, 2.5, 2.5);
    EXPECT_FALSE(triangle.IsCorrect());
}

TEST_F(TriangleTest, Can_Detect_Correct_Triangle) {
    SetValue(0, 0, 5, 5, 0, 3);
    EXPECT_TRUE(triangle.IsCorrect());
}

TEST_F(TriangleTest, Can_Detect_Equilateral_Triangle) {
    SetValue(0, 0, 3, 5, 5, 3);
    EXPECT_EQ(true, triangle.IsEquilateral());
}

TEST_F(TriangleTest, Can_Detect_Not_Equilateral_Triangle) {
    SetValue(0, 0, 3, 7, 5, 3);
    EXPECT_EQ(false, triangle.IsEquilateral());
}

TEST_F(TriangleTest, Can_Detect_Isosceles_Triangle) {
    SetValue(0, 0, 5, 0, 2.5, static_cast<float>(4.33012719));
    EXPECT_EQ(true, triangle.IsIsosceles());
}

TEST_F(TriangleTest, Can_Detect_Not_Isosceles_Triangle) {
    SetValue(0, 0, 3, 7, 5, 3);
    EXPECT_EQ(false, triangle.IsIsosceles());
}

TEST_F(TriangleTest, Can_Calculate_Side) {
    SetValue(0, 0, 3, 7, 5, 3);
    EXPECT_TRUE(fabs(triangle.Length(A, B) - 7.62) <= 0.01);
}

TEST_F(TriangleTest, Can_Calculate_Angle) {
    SetValue(0, 0, 5, 0, 2.5, static_cast<float>(4.33012719));
    EXPECT_TRUE(fabs(triangle.Angle(A) - 60) <= 0.01);
}

TEST_F(TriangleTest, Can_Calculate_Square) {
    SetValue(0, 6, 3, 0, 0, 0);
    EXPECT_TRUE(fabs(triangle.Square() - 9) <= 0.01);
}

TEST_F(TriangleTest, Can_Calculate_Perimeter) {
    SetValue(0, 3, 0, 0, 4, 0);
    EXPECT_TRUE(fabs(triangle.Perimeter() - 12) <= 0.01);
}

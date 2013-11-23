// Copyright 2013 Kirill Kornyakov

#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Weffc++"
#if defined(__clang__)
    #pragma GCC diagnostic ignored "-Wglobal-constructors"
#elif defined(__GNUC__)
    #pragma GCC diagnostic ignored "-Wctor-dtor-privacy"
#endif

#include <gtest/gtest.h>

TEST(MathTest, TwoPlusTwoEqualsFour) {
    EXPECT_EQ(2 + 2, 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#pragma GCC diagnostic pop

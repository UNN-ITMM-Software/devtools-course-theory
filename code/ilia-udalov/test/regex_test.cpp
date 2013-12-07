// Copyright 2013 Ilia Udalov

#include <gtest/gtest.h>

#include <limits.h>
#include <string>

#include "library/regex.h"

class RegexTest : public ::testing::Test {
};

///////////////////////////////////////////////////////////////////////////////
// match
///////////////////////////////////////////////////////////////////////////////
TEST_F(RegexTest, Match_Any_String) {
    EXPECT_EQ(1, match(std::string(".*"), std::string("banana")));
}

TEST_F(RegexTest, Match_Same_String) {
    EXPECT_EQ(1, match(std::string("banana"), std::string("banana")));
}

TEST_F(RegexTest, Not_Match_String) {
    EXPECT_EQ(0, match(std::string("pure functions"),
        std::string("objects are so awesome")));
}

TEST_F(RegexTest, Match_Beginig_Of_String) {
    EXPECT_EQ(1, match(std::string("^is"), std::string("is match")));
}

TEST_F(RegexTest, Not_Match_Beginig_Of_String) {
    EXPECT_EQ(0, match(std::string("^match"), std::string("is not match")));
}

TEST_F(RegexTest, Not_Match_End_Of_String) {
    EXPECT_EQ(0, match(std::string("not$"), std::string("is not match")));
}

TEST_F(RegexTest, Match_Regexp_With_Points_String) {
    EXPECT_EQ(1, match(std::string("S.W.A.T"), std::string("SOWTAAT?")));
}

///////////////////////////////////////////////////////////////////////////////
// find
///////////////////////////////////////////////////////////////////////////////


TEST_F(RegexTest, Just_Find_String) {
    EXPECT_EQ(12, find(std::string("Haskell"),
        std::string("Do you know Haskell well?")));
}

TEST_F(RegexTest, Find_Same_String) {
    EXPECT_EQ(0, find(std::string("banana"), std::string("banana")));
}

TEST_F(RegexTest, Find_Substring_Longer_Then_String) {
    EXPECT_EQ(-1, find(std::string("banananananana"), std::string("banana")));
}

TEST_F(RegexTest, Not_Find_String) {
    EXPECT_EQ(-1, find(std::string("Copyright"),
        std::string("Copyleft 2013 Ilia Udalov")));
}

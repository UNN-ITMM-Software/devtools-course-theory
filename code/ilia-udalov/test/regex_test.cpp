// Copyright 2013 Ilia Udalov

#include <gtest/gtest.h>

#include <limits.h>
#include <string>

#include "library/regex.h"

///////////////////////////////////////////////////////////////////////////////
// match
///////////////////////////////////////////////////////////////////////////////

TEST(MatchTest, Match_Basic_Regex) {
    EXPECT_EQ(1, match(std::string(".*"), std::string("banana")));
    EXPECT_EQ(1, match(std::string("banana"), std::string("banana")));
    EXPECT_EQ(0, match(std::string("pure functions"),
        std::string("objects are so awesome")));
    EXPECT_EQ(1, match(std::string(""),
        std::string("objects are so awesome")));
}

TEST(MatchTest, Match_Beginig_Of_String) {
    EXPECT_EQ(1, match(std::string("^is"), std::string("is match")));
    EXPECT_EQ(0, match(std::string("^match"), std::string("is not match")));
}

TEST(MatchTest, Match_End_Of_String) {
    EXPECT_EQ(1, match(std::string("match$"), std::string("is match")));
    EXPECT_EQ(0, match(std::string("not$"), std::string("is not match")));
}

TEST(MatchTest, Match_Begining_And_End_Of_String) {
    EXPECT_EQ(1, match(std::string("^repeat$"), std::string("repeat")));
    EXPECT_EQ(0, match(std::string("^play$"),
        std::string("I can play guitar!")));
}

TEST(MatchTest, Match_Regex_With_Points_String) {
    EXPECT_EQ(1, match(std::string("S.W.A.T"), std::string("SOWTAAT?")));
}

TEST(MatchTest, Match_Complex_Regex) {
    EXPECT_EQ(1, match(std::string("^My.name.*Ilia$"),
        std::string("My name is Ilia")));
    EXPECT_EQ(0, match(std::string("^My.name.*Vova$"),
        std::string("My name is Ilia")));
    EXPECT_EQ(1, match(std::string("^My.name.*"),
        std::string("My name is Jon")));
}

///////////////////////////////////////////////////////////////////////////////
// find
///////////////////////////////////////////////////////////////////////////////


TEST(FindTest, Just_Find_String) {
    EXPECT_EQ(12, find(std::string("Haskell"),
        std::string("Do you know Haskell well?")));
    EXPECT_EQ(8, find(std::string("west"),
        std::string("East or west, home is best.")));
}

TEST(FindTest, Find_Same_String) {
    EXPECT_EQ(0, find(std::string("banana"), std::string("banana")));
}

TEST(FindTest, Find_Substring_Longer_Then_String) {
    EXPECT_EQ(-1, find(std::string("banananananana"), std::string("banana")));
    EXPECT_EQ(-1, find(std::string("yahooooooooooo"), std::string("yahooo")));
}

TEST(FindTest, Not_Find_String) {
    EXPECT_EQ(-1, find(std::string("Copyright"),
        std::string("Copyleft 2013 Ilia Udalov")));
}

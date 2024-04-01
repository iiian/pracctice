#include "wildcard_matching.h"
#include <gtest/gtest.h>

using namespace std;

TEST(WildcardTesting, MainTest) {
  EXPECT_FALSE(isMatch("aa", "a"));
  EXPECT_TRUE(isMatch("aa", "*"));
  EXPECT_FALSE(isMatch("cb", "?a"));
  EXPECT_TRUE(isMatch("cmd018send the message; args[];", "cmd???*; args*;"));
  EXPECT_FALSE(isMatch("acdcb", "a*c?b"));
  EXPECT_TRUE(isMatch("", "*****"));
  EXPECT_TRUE(isMatch("abcabczzzde", "*abc???de*"));
}


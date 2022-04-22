#include "pch.h"

#include "gtest/gtest.h"

#include "../LeetCode/LeetCode.h"

TEST(TestCase_LeetCode_TwoSum, Test1) {
	LeetCode::Solution sln;

	auto response = sln.twoSum({ 2,7,11,15 }, 9); // 2 + 7 == 9
	ASSERT_EQ(response.size(), 2);	// [0, 1] or [1, 0] are both correct
	EXPECT_TRUE(std::find(response.begin(), response.end(), 0) != response.end());
	EXPECT_TRUE(std::find(response.begin(), response.end(), 1) != response.end());

	response = sln.twoSum({ 3,2,4 }, 6);  // 2 + 4 == 6
	ASSERT_EQ(response.size(), 2);	// [1, 2] or [2, 1] are both correct
	EXPECT_TRUE(std::find(response.begin(), response.end(), 1) != response.end());
	EXPECT_TRUE(std::find(response.begin(), response.end(), 2) != response.end());
}

TEST(TestCase_LeetCode_LongestSubstring, Test1) {
	LeetCode::Solution sln;

	EXPECT_EQ(sln.lengthOfLongestSubstring(" "), 1);
	EXPECT_EQ(sln.lengthOfLongestSubstring("aab"), 2);
	EXPECT_EQ(sln.lengthOfLongestSubstring("dvdf"), 3);
	EXPECT_EQ(sln.lengthOfLongestSubstring("abcabcbb"), 3);
	EXPECT_EQ(sln.lengthOfLongestSubstring("bbbbb"), 1);
	EXPECT_EQ(sln.lengthOfLongestSubstring("pwwkew"), 3);
}

TEST(TestCase_LeetCode_FirstMissingPositive, DISABLED_Test1) {
	LeetCode::Solution sln;

	EXPECT_EQ(sln.firstMissingPositive({ 1, 2, 0 }), 3);
	EXPECT_EQ(sln.firstMissingPositive({ 3, 4, -1, 1 }), 2);
	EXPECT_EQ(sln.firstMissingPositive({ 7, 8, 9, 11, 12 }), 1);
}

TEST(TestCase_LeetCode_MaxProfit, Test1) {
	LeetCode::Solution sln;

	EXPECT_EQ(sln.maxProfit({ 7, 1, 5, 3, 6, 4 }), 7);
	EXPECT_EQ(sln.maxProfit({ 1, 2, 3, 4, 5 }), 4);
}

TEST(TestCase_LeetCode_Reverse, Test1) {
	LeetCode::Solution sln;

	EXPECT_EQ(sln.reverse(123), 321);
	EXPECT_EQ(sln.reverse(964632435), 534236469);
	EXPECT_EQ(sln.reverse(1964632435), 0);
	EXPECT_EQ(sln.reverse(-2147483648), 0);
}

TEST(TestCase_LeetCode_SuperPow, Test1) {
	LeetCode::Solution sln;

	EXPECT_EQ(sln.superPow(2, { 1, 5 }), 680);
}

#include "pch.h"

#include "gtest/gtest.h"

#include "../HackerRank/HackerRank.h"

TEST(TestCase_HackerRank_candies, Test1) {
	HackerRank::Solution sln;

	EXPECT_EQ(sln.candies({ 1 }), 1);
	EXPECT_EQ(sln.candies({ 5 }), 1);
	EXPECT_EQ(sln.candies({ 1, 1 }), 2);
	EXPECT_EQ(sln.candies({ 5, 5 }), 2);
	EXPECT_EQ(sln.candies({ 1, 2 }), 3);
	EXPECT_EQ(sln.candies({ 2, 1 }), 3);
	EXPECT_EQ(sln.candies({ 1, 3 }), 3);
	EXPECT_EQ(sln.candies({ 3, 1 }), 3);
	EXPECT_EQ(sln.candies({ 5, 4 }), 3);
	EXPECT_EQ(sln.candies({ 4, 5 }), 3);
	EXPECT_EQ(sln.candies({ 6, 4 }), 3);

	EXPECT_EQ(sln.candies({ 1, 1, 1 }), 3);
	EXPECT_EQ(sln.candies({ 5, 5, 5 }), 3);
	EXPECT_EQ(sln.candies({ 1, 2, 3 }), 6);
	EXPECT_EQ(sln.candies({ 1, 2, 2 }), 4);
	EXPECT_EQ(sln.candies({ 2, 1, 1 }), 4);
	EXPECT_EQ(sln.candies({ 1, 2, 1 }), 4);
	EXPECT_EQ(sln.candies({ 3, 2, 1 }), 6);
	EXPECT_EQ(sln.candies({ 1, 1, 2 }), 4);
	EXPECT_EQ(sln.candies({ 2, 1, 2 }), 5);
	EXPECT_EQ(sln.candies({ 3, 1, 3 }), 5);
	EXPECT_EQ(sln.candies({ 1, 3, 1 }), 4);
	EXPECT_EQ(sln.candies({ 3, 2, 2 }), 4);

	EXPECT_EQ(sln.candies({ 4, 3, 2, 1 }), 10);
	EXPECT_EQ(sln.candies({ 1, 4, 2, 1, 1 }), 8);
	EXPECT_EQ(sln.candies({ 1, 2, 2, 2, 1 }), 7);
	EXPECT_EQ(sln.candies({ 1, 4, 3, 2, 1 }), 11);
	EXPECT_EQ(sln.candies({ 1, 4, 2, 1 }), 7);
	EXPECT_EQ(sln.candies({ 1, 2, 4, 1 }), 7);
	EXPECT_EQ(sln.candies({ 1, 2, 3, 2, 1 }), 9);
	EXPECT_EQ(sln.candies({ 1, 4, 3, 3, 2, 1 }), 10);
	EXPECT_EQ(sln.candies({ 1, 4, 4, 3, 2, 1 }), 13);
	EXPECT_EQ(sln.candies({ 3, 2, 1, 2, 3 }), 11);
	EXPECT_EQ(sln.candies({ 1, 4, 5, 1, 1 }), 8);
	EXPECT_EQ(sln.candies({ 1, 4, 1, 2, 1 }), 7);
	EXPECT_EQ(sln.candies({ 1, 4, 4, 2, 1 }), 9);
	EXPECT_EQ(sln.candies({ 1, 4, 3, 2, 1 }), 11);
	EXPECT_EQ(sln.candies({ 1, 4, 5, 1, 1, 1 }), 9);
	EXPECT_EQ(sln.candies({ 1, 4, 5, 2, 1, 1 }), 10);
	EXPECT_EQ(sln.candies({ 6, 4, 4, 2 }), 6);
	EXPECT_EQ(sln.candies({ 10, 3, 8, 8, 4, 4 }), 9);
	EXPECT_EQ(sln.candies({ 2, 4, 2, 6, 1, 7, 8, 9, 2, 1 }), 19);
	EXPECT_EQ(sln.candies({ 2, 4, 3, 5, 2, 6, 4, 5 }), 12);
	EXPECT_EQ(sln.candies({ 9, 2, 3, 6, 5, 4, 3, 2, 2, 2 }), 22);
}

TEST(TestCase_HackerRank_candies, LargeDataTest) {
	HackerRank::Solution sln;

	std::ifstream fin;

	fin.open("data\\Candies-Testcase-1.txt", std::ifstream::in);
	ASSERT_TRUE(fin.is_open());

	int64_t v, n, expectedResult;
	fin >> expectedResult;
	fin >> n;
	std::vector<int64_t> inputValues;
	inputValues.reserve(static_cast<size_t>(n));
	while (!fin.eof()) {
		fin >> v;
		inputValues.push_back(v);
	}
	fin.close();

	EXPECT_EQ(sln.candies(inputValues), expectedResult);
}
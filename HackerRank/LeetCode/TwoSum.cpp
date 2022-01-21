
/*
https://leetcode.com/problems/two-sum/

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

#include <assert.h>
#include <iostream>
#include <cstdio>
#include <sstream>

#include <algorithm>
//#include <cmath>
//#include <cstdio>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iosfwd>
#include <memory>
#include <map>
#include <unordered_map>
#include <vector>

namespace {
	class Solution {
	public:
		std::vector<int> twoSum(const std::vector<int>& nums, int target) {
			std::vector<int> ret;
			std::map<int, int> m;

			for (auto j = nums.cbegin(); j < nums.cend(); ++j) {
				m[*j] = static_cast<int>(std::distance(nums.begin(), j));
			}

			for (auto i = nums.begin(); i < nums.end(); ++i) {
				auto j = m.find(target - *i);

				if (j != m.end() && j->second != std::distance(nums.begin(), i)) {
					ret.push_back(static_cast<int>(std::distance(nums.begin(), i)));
					ret.push_back(j->second);
					return ret;
				}
			}

			return ret;
		}
	};
}

void LeetCode_TwoSum_Test() {
	Solution s;

	auto response = s.twoSum({ 2,7,11,15 }, 9);
	std::cout << "Response: [" << response[0] << " " << response[1] << "]" << std::endl;
	response = s.twoSum({ 3,2,4 }, 6);
	std::cout << "Response: [" << response[0] << " " << response[1] << "]" << std::endl;
}

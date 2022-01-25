
/*
https://leetcode.com/problems/two-sum/

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

#include "pch.h"

#include "LeetCode.h"

namespace LeetCode {

	std::vector<int> Solution::twoSum(const std::vector<int>& nums, int target) {
		std::vector<int> ret(2);
		std::unordered_map<int, int> m(nums.size() - 1);
		// map of the values in the array to the index at which that value is located.
		// the unordered_map (a hash map) is much faster than the map (a binary tree)

		for (auto j = nums.cbegin(); j < nums.cend(); ++j) {
			auto i = m.find(target - *j);
			if (i != m.end()) {
				ret[0] = static_cast<int>(std::distance(nums.begin(), j));
				ret[1] = i->second;
				break;
			}
			else {
				m[*j] = static_cast<int>(std::distance(nums.begin(), j));
			}
		}

		return ret;
	}
}

//void LeetCode_TwoSum_Test() {
//	LeetCode::Solution s;
//
//	auto response = s.twoSum({ 2,7,11,15 }, 9);
//	std::cout << "Response: [" << response[0] << " " << response[1] << "]" << std::endl;
//	response = s.twoSum({ 3,2,4 }, 6);
//	std::cout << "Response: [" << response[0] << " " << response[1] << "]" << std::endl;
//}

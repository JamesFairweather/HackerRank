// https://leetcode.com/problems/first-missing-positive/
//
// Given an unsorted integer array nums, return the smallest missing positive integer.
//
// You must implement an algorithm that runs in O(n) time and uses constant extra space.

#include "pch.h"

#include "LeetCode.h"

namespace LeetCode {

    int Solution::firstMissingPositive(const std::vector<int>& nums) {

        // This problem is unsolved at this time
        std::set<int, std::less<int>> tree_values;

        for (auto v : nums) {
            if (v > 0) {
                tree_values.insert(v);
            }
        }

        // The tree is sorted so the smallest value is at the top
        int smallest_value = *tree_values.begin();

        return smallest_value - 1;
    }

}

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/
//
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
//
// On each day, you may decide to buyand /or sell the stock.You can only hold at most one share of the stock at any time.However, you can buy it then immediately sell it on the same day.
//
// Find and return the maximum profit you can achieve.

#include "pch.h"

#include "LeetCode.h"

namespace LeetCode {

    int Solution::maxProfit(const std::vector<int>& prices) {
        int totalProfit = 0;

        if (prices.empty()) {
            return 0;
        }

        int purchasePrice = prices[0];

        auto current = prices.begin() + 1;
        while (current != prices.end()) {
            if (*current >= *(current-1)) {
                // hang onto the stock until it reaches a peak
            }
            else {
                // the price went down, so we sell at yesterday's price
                totalProfit += (*(current - 1) - purchasePrice);

                // buy the share back at today's price
                purchasePrice = *current;
            }

            current++;
        }

        int endingDiff = *(current-1) - purchasePrice;
        if (endingDiff > 0) {
            totalProfit += endingDiff;
        }

        return totalProfit;
    }

}

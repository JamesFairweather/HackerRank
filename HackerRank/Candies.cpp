
// Problem:
// 
// https://www.hackerrank.com/challenges/candies/problem
//
// Alice is a kindergarten teacher.  She wants to give some candies to the children in her class.  All the children sit in a line
// and each of them has a rating score according to his or her performance in the class.  Alice wants to give at least 1 candy to each
// child.  If two children sit next to each other, then the one with the higher rating must get more candies.  Alice wants to minimize
// the total number of candies she must buy.

#include "HackerRank.h"

namespace HackerRank {

	int64_t Solution::candies(const std::vector<int64_t>& arr) {

		int n = static_cast<int>(arr.size());

		if (n < 2) {
			return n;
		}

		std::vector<int64_t> max_values(n, 0);

		// forward track
		for (int i = 1; i < n; i++) {
			if (arr[i] > arr[i - 1]) {
				max_values[i] = max_values[i - 1] + 1;
			}
		}

		// backwards track
		for (int i = n - 2; i >= 0; i--) {
			if (arr[i] > arr[i + 1] && max_values[i] <= max_values[i + 1]) {
				max_values[i] = max_values[i + 1] + 1;
			}
		}

		int64_t result = n;
		std::for_each(max_values.begin(), max_values.end(), [&result](int64_t v) {
			result += v;
		});

		return result;

	}
}

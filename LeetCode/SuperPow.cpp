// https://leetcode.com/problems/super-pow/
//
// Your task is to calculate a^b mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

#include "pch.h"

#include "LeetCode.h"

namespace LeetCode {

    int Solution::superPow(int a, const std::vector<int>& b) {

        const int modulus = 1337;

        int power = 0;

        for (auto v = b.rbegin(); v != b.rend(); ++v) {

            int exp = 1;
            for (int i = 0; i < std::distance(b.rbegin(), v); ++i) {
                exp *= 10;
            }

            power += *v *exp;

            if (power > modulus)
                break;
        }

        power = power % modulus;

        int ret = 1;
        while (power != 0) {
            ret *= a;
            --power;
        }

        int c = ret % modulus;
        return c;
    }
}

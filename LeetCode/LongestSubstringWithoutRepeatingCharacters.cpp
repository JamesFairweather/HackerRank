
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Given a string s, find the length of the longest substring without repeating characters.

#include "pch.h"
#include "LeetCode.h"

namespace LeetCode {
    int Solution::lengthOfLongestSubstring(const std::string& s) {

        std::bitset<256> subString;

        if (s.empty()) {
            return 0;
        }

        std::size_t longestSubstring = 0;
        std::size_t currentSubstringLength = 0;
        auto startSeq = s.begin();

        for (auto i = s.begin(); i != s.end(); ++i) {

            if (!subString.test(*i)) {
                subString.set(*i);
                ++currentSubstringLength;
            }
            else {
                if (longestSubstring < currentSubstringLength) {
                    longestSubstring = currentSubstringLength;
                }

                do {
                    // advance the trailing pointer until the duplicate entry is removed.
                    subString.reset(*startSeq);
                    ++startSeq;
                    --currentSubstringLength;
                } while (subString.test(*i));

                subString.set(*i);
                ++currentSubstringLength;
            }
        }

        if (longestSubstring < currentSubstringLength) {
            longestSubstring = currentSubstringLength;
        }

        return static_cast<int>(longestSubstring);
    }
}

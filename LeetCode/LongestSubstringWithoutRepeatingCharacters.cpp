
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Given a string s, find the length of the longest substring without repeating characters.

#include "pch.h"
#include "LeetCode.h"

namespace LeetCode {
    int Solution::lengthOfLongestSubstring(const std::string& s) {

        std::set<char> subString;

        if (s.empty()) {
            return 0;
        }

        std::size_t longestSubstring = 0;
        auto startSeq = s.begin();

        for (auto i = s.begin(); i != s.end(); ++i) {
            if (subString.find(*i) == subString.end()) {
                subString.insert(*i);
            }
            else {
                if (longestSubstring < subString.size()) {
                    longestSubstring = subString.size();
                }

                do {
                    // advance the trailing pointer until the duplicate entry is removed.
                    subString.erase(*startSeq);
                    ++startSeq;
                } while (subString.find(*i) != subString.end());

                subString.insert(*i);
            }
        }

        if (longestSubstring < subString.size()) {
            longestSubstring = subString.size();
        }

        return static_cast<int>(longestSubstring);
    }
}

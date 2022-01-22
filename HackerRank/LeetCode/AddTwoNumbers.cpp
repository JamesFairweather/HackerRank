// https://leetcode.com/problems/add-two-numbers/
/*
 * You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order, and each of their nodes contains a single digit.Add the two numbersand return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode() : val(0), next(nullptr) {}
  *     ListNode(int x) : val(x), next(nullptr) {}
  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
  * };
  */

#include <iostream>
#include <memory>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* ret = l1;
        int carry = 0;
        int l2_val = 0;

        for(;;) {
            l2_val = 0;
            if (l2 != nullptr) {
                l2_val = l2->val;
                l2 = l2->next;
            }

            l1->val += l2_val + carry;
            carry = 0;
            if (l1->val > 9) {
                l1->val -= 10;
                carry = 1;
            }

            if (l1->next == nullptr) {
                if (l2 == nullptr) {
                    break; // for(;;)
                }
                else {
                    // join l2 to l1
                    l1->next = l2;
                    l2 = nullptr;
                }
            }

            l1 = l1->next;
        }

        if (carry != 0) {
            l1->next = new ListNode(1);
        }

        return ret;
    }
};

ListNode* makeList(const std::vector<int>& input) {
    ListNode *head = nullptr, *current = nullptr;

    for (auto v : input) {
        ListNode* node = new ListNode(v);

        if (current != nullptr) {
            current->next = node;
        }
        else {
            head = node;
        }
        current = node;
    }

    return head;
}

void LeetCode_AddTwoNumbers_Test() {
    Solution s;

    auto l1 = makeList({ 1, 9, 9 }); 
    auto l2 = makeList({ 9 });

    auto result = s.addTwoNumbers(l2, l1);

    for (;;) {
        std::cout << result->val;
        result = result->next;
        if (result != nullptr) {
            std::cout << ", ";
        }
        else {
            std::cout << std::endl;
            break;
        }
    }
}

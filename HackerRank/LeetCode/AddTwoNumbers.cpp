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

        int carry = 0;

        while (l1->next != nullptr) {
            int l2_value = 0;
            if (l2 != nullptr) {
                l2_value = l2->val;
                l2 = l2->next;
            }

            l1->val += l2_value + carry;
            carry = 0;
            if (l1->val > 9) {
                l1->val -= 10;
                carry = 1;
            }

            l1 = l1->next;
        }

        if (l2 != nullptr) {
            l1->next = l2;
            l2->val += carry;

            if (l2->val > 9) {
                if (l2->next) {
                    l2->next->val++;
                }
                else {

                }
            }



        }

        return l1;
    }
};

void LeetCode_AddTwoNumbers_Test() {
    Solution s;

    std::shared_ptr<ListNode> l1 = std::make_shared<ListNode>(5);

    s.addTwoNumbers(l1.get(), nullptr);

    while (l1 != nullptr) {
        std::cout << l1->val;
        l1 = l1->next;
    }

}

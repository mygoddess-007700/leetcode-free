/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
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
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
    ListNode* reverseList(ListNode * head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode * pre = nullptr;
        ListNode * cur = head;
        while (cur != nullptr)
        {
            ListNode * nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;

        // if (head == nullptr || head->next == nullptr)
        // {
        //     return head;
        // }
        // ListNode * p = reverseList(head->next);
        // head->next->next = head;
        // head->next = nullptr;
        // return p;
    }

};
// @lc code=end


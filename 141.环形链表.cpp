/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

    bool hasCycle(ListNode * head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        ListNode * slow = head;
        ListNode * fast = head->next;
        while (slow != fast)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
        // ListNode * t = head;
        // set<ListNode *> s;
        // while (t != nullptr)
        // {
        //     if (s.count(t))
        //     {
        //         return true;
        //     }
        //     s.emplace(t);
        //     t = t->next;
        // }
        // return false;
    }
};
// @lc code=end


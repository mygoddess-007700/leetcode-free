/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode * pHead = new ListNode(-1, head);
        ListNode * t = pHead;
        while (t->next != nullptr)
        {
            if (t->next->val == val)
            {
                t->next = t->next->next;
            }
            else
            {
                t = t->next;
            }
        }
        return pHead->next;
        // ListNode * t1 = head;
        // ListNode * t2 = new ListNode(-1, head);
        // ListNode * t = t2;
        // while (t1 != nullptr)
        // {
        //     if (t1->val == val)
        //     {
        //         t1 = t1->next;
        //         t2->next = t1;
        //     }
        //     else
        //     {
        //         t1 = t1->next;
        //         t2 = t2->next;
        //     }
        // }
        // return t->next;
    }
};
// @lc code=end


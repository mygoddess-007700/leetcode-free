/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode * p = new ListNode();
        ListNode * t = p;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val > list2->val)
            {
                t->next = list2;
                list2 = list2->next;
            }
            else
            {
                t->next = list1;
                list1 = list1->next;
            }
            t = t->next;
        }
        if (list1 == nullptr)
        {
            t->next = list2;
        }
        if (list2 == nullptr)
        {
            t->next = list1;
        }
        return p->next;

    }
};
// @lc code=end


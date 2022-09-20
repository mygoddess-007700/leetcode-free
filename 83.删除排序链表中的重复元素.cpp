/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode * p = new ListNode(-200, head);
        int val = -200;
        while (p->next != nullptr)
        {
            if (p->next->val == val)
            {
                p->next = p->next->next;
            }
            else
            {
                val = p->next->val;
                p = p->next;
            }
            
        }
        return head;
    }
};
// @lc code=end


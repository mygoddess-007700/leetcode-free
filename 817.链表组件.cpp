/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
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
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    int numComponents(ListNode* head, vector<int>& nums) {
        set<int> s;
        for (int & t : nums)
        {
            s.emplace(t);
        }
        int ans = 0;
        while (head)
        {
            if (s.count(head->val))
            {
                head = head->next;
                while (head != nullptr && s.count(head->val))
                {
                    head = head->next;
                }
                ans++;
                continue;
            }
            head = head->next;
        }
        return ans;
    }
};
// @lc code=end


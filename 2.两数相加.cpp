/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
#include<bits/stdc++.h>
using namespace std;
//   struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
// };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(l1 == nullptr)
        {
            return nullptr;
        }
        int len = 0;
        ListNode * p1, * p2;
        int x1 = 0, x2 = 0;
        for(p1=l1; p1!=nullptr; p1=p1->next)
        { 
            x1 = x1*10 + p1->val;
            len++;
        }
        for(p2=l2; p2!=nullptr; p2=p2->next)
        { 
            x2 = x2*10 + p2->val;
            len++;
        }
        int x = x1 + x2;

        int lenX = 0;
        unordered_map<int, int> hashmap;
        vector<int> sums;
        while(x)
        {
            sums.push_back(x/10);
            x /= 10;
        }

        ListNode * first = new ListNode(sums[sums.size()-1]);
        for(int i=sums.size()-2; i>=0; i--)
        {
            ListNode * p = first;
            while(p->next != nullptr)
            {
                p = p->next;
            }
            ListNode * node = new ListNode(sums[i]);
            p->next = node;
        }
        return first;
    }
};
// @lc code=end


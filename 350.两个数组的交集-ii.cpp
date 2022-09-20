/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return intersect(nums2, nums1);
        }

        unordered_map<int, int> hashmap;
        vector<int> intersect;
        for (int i = 0; i < nums1.size(); i++)
        {
            hashmap[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            //count是键的个数！！！
            if (hashmap.count(nums2[i]))
            {
                intersect.push_back(nums2[i]);
                hashmap[nums2[i]]--;
                if (hashmap[nums2[i]] == 0)
                {
                    hashmap.erase(nums2[i]);
                }
            }
        }
        return intersect;
    }
};
// @lc code=end


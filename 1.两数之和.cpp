/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> obj;
        unordered_map<int, int> hashmap;
        for(int i=0; i<nums.size(); i++)
        {
            auto it = hashmap.find(target-nums[i]);
            if(it != hashmap.end())
            {
                return{i, it->second};
            }
            hashmap[nums[i]] = i;
        }
        return{};
    }
};
// @lc code=end


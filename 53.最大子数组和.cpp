/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    struct Status{int lSum, rSum, mSum, aSum;};

    Status PushUp(Status l, Status r)
    {
        int lSum = max(l.lSum, l.aSum + r.lSum);
        int rSum = max(r.rSum, r.aSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        int aSum = l.aSum + r.aSum;
        return {lSum, rSum, mSum, aSum};
    }

    //不加引用就超时间
    Status Get(vector<int> & array, int l, int r)
    {
        if (l == r)
        {
            return {array[l], array[l], array[l], array[l]};
        }
        int m = (l + r) >> 1;
        Status s1 = Get(array, l, m);
        Status s2 = Get(array, m+1, r);
        return PushUp(s1, s2);
    }

    int maxSubArray(vector<int>& nums)
    {
        return Get(nums, 0, nums.size()-1).mSum;
        // 动态规划
        // int pre = 0;
        // int maxNum = nums[0];
        // for (const auto & x: nums)
        // {
        //     pre = max(x, pre + x);
        //     maxNum = max(pre, maxNum);
        // }
        // return maxNum;
        // 第一次
        // long long maxSum = nums[0];
        // long long sum = 0; 
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for (int j = i; j < nums.size(); j++)
        //     {
        //         sum += nums[j];
        //         if (sum > maxSum)
        //         {
        //             maxSum = sum;
        //         }
        //         if (sum <= 0)
        //         {
        //             break;
        //         }  
        //     }
        //     sum = 0;
        // }
        // return maxSum;
    }
};
// @lc code=end


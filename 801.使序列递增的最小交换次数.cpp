/*
 * @lc app=leetcode.cn id=801 lang=cpp
 *
 * [801] 使序列递增的最小交换次数
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int ** dp = new int * [2];
        for (int i = 0; i < 2; i++)
        {
            dp[i] = new int[2];
        }
        dp[0][0] = 0;
        dp[0][1] = 1;
        for (int i = 1; i < n; i++)
        {
            int pre = i-1 & 1;
            int cur = i & 1;
            int a1 = nums1[i-1], a2 = nums1[i], b1 = nums2[i-1], b2 = nums2[i];
            if (a2 > a1 && b2 > b1 && a2 > b1 && b2 > a1)
            {
                dp[cur][0] = min(dp[pre][0], dp[pre][1]);
                dp[cur][1] = dp[cur][0] + 1;
            }
            else if (a2 > a1 && b2 > b1)
            {
                dp[cur][0] = dp[pre][0];
                dp[cur][1] = dp[pre][1] + 1;
            }
            else
            {
                dp[cur][0] = dp[pre][1];
                dp[cur][1] = dp[pre][0] + 1;
            }
        }
        int cur = (n-1) & 1;
        return min(dp[cur][0], dp[cur][1]);
    }
};
// @lc code=end


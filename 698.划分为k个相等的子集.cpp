/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    bool traversal(vector<int>& nums, int index, vector<int>& bucket)
    {
        if (index == len) return true;
        for (int j = 0; j < k; j++)
        {
            if (j > 0 && bucket[j] == bucket[j-1]) continue;
            if (bucket[j] + nums[index] > s) continue;
            bucket[j] += nums[index];
            if (traversal(nums, index + 1, bucket)) return true;
            bucket[j] -= nums[index];
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //回溯+剪枝
        len = nums.size();
        this->k = k;
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        s = sum / k;
        if (sum % k != 0 || s < nums[0]) return false;
        vector<int> bucket(k, 0);
        bucket[0] = nums[0];

        if (traversal(nums, 1, bucket)) return true;
        else return false;

        //状态压缩+记忆化搜索
    }
private:
    int len;
    int k;
    int s;
};
// @lc code=end


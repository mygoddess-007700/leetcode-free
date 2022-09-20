/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums)
    {
        unordered_set<long> set;
        long mi = nums[0];
        int index = 0;
        int n = nums.size();
        set.insert(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > mi)
            {
                index++;
                if (index == 2)
                {
                    return true;
                }
                mi = nums[i];
            }
            else
            {
                int t;
                for (long x : set)
                {
                    t = min(x, mi);
                    if (t < nums[i])
                    {
                        mi = t;
                    }
                    else
                    {
                        mi = nums[i];
                        index--;
                    }
                }
            }
            if (index == 2)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end


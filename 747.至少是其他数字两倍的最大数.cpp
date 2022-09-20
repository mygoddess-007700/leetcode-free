/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int dominantIndex(vector<int>& nums)
    {
        // int n = nums.size();
        // int m1 = -1, ma = -1;
        // int index = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     if (nums[i] > ma)
        //     {
        //         m1 = ma;
        //         ma = nums[i];
        //         index = i;
        //     }
        //     else if (nums[i] > m1)
        //     {
        //         m1 = nums[i];
        //     }
        // }
        // return (ma >= 2 * m1) ? index : -1;

        int n = nums.size(), mx = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= mx * 2)
            {
                ans = i;
            }
            else if (nums[i] * 2 > mx)
            {
                ans = -1;
            }
            mx = max(mx, nums[i]);
        }
        return ans;

        // int n = nums.size();
        // int tMax2 = nums[0] / 2;
        // int tMax = nums[0];
        // int index = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     if (nums[i] > tMax2)
        //     {
        //         if (nums[i] >= tMax)
        //         {
        //             tMax = 2 * nums[i];
        //             tMax2 = nums[i] / 2;
        //             index = i;
        //             cout<<index<<endl;
        //         }
        //         else
        //         {
        //             tMax2 = nums[i];
        //             tMax = 2 * nums[i];
        //             index = -1;
        //         }
                
        //     }
        // }
        // return index;
    }
};
// @lc code=end


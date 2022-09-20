/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> t;
        for (int x: nums)
        {
            if (t.find(x) != t.end())
            {
                return true;
            }
            t.insert(x);
        }
        return false;

        // 第二次
        // vector<int> t;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for (auto p = t.begin(); p != t.end(); p++)
        //     {
        //         if (nums[i] == *p)
        //         {
        //             return true;
        //         }
        //     }
        //     t.emplace_back(nums[i]);
        // }
        // return false;
        //第一次
        // QuickSort(nums, 0, nums.size()-1);
        //第三次
        // sort(nums.begin(), nums.end());
        // for (auto p = nums.begin(); p != nums.end()--; p++)
        // {
        //     if (*p == *(p+1))
        //     {
        //         return true;
        //     }
        // }
        // return false;
    }

    // void QuickSort(vector<int>& nums, int low, int high)
    // {
    //     if (low < high)
    //     {
    //         int poivt = Partion(nums, low, high);
    //         QuickSort(nums, low, poivt-1);
    //         QuickSort(nums, poivt+1, high);
    //     }
    // }

    // int Partion(vector<int>& nums, int low, int high)
    // {
    //     int t = nums[low];
    //     while (low < high)
    //     {
    //         while (nums[high] >= t && high > low)
    //         {
    //             high--;
    //         }
    //         nums[low] = nums[high];
    //         while(nums[low] <= t && low < high)
    //         {
    //             low++;
    //         }
    //         nums[high] = nums[low];
    //     }
    //     nums[low] = t;
    //     return low;
    // }
};
// @lc code=end


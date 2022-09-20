/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int p1 = m - 1;
        int p2 = n - 1;
        int tail = m + n -1;
        int cur;
        while (p1 >= 0 || p2 >= 0)
        {
            if (p1 == -1)
            {
                cur = nums2[p2];
                p2--;
            }
            else if (p2 == -1)
            {
                cur = nums1[p1];
                p1--;
            }
            else if (nums1[p1] > nums2[p2])
            {
                cur = nums1[p1];
                p1--;
            }
            else if (nums1[p1] <= nums2[p2])
            {
                cur = nums2[p2];
                p2--;
            }
            nums1[tail] = cur;
            tail--;
        }
        // int i = 0;
        // vector<int> t1;
        // for (int j = 0; j < m; j++)
        // {
        //     t1.emplace_back(nums1[j]);
        // }
        // auto p1 = t1.begin();
        // auto p2 = nums2.begin();
        // while (p1 != t1.end() && p2 != nums2.end())
        // {
        //     if (*p1 <= *p2)
        //     {
        //         nums1[i] = *p1;
        //         p1++;
        //     }
        //     else
        //     {
        //         nums1[i] = *p2;
        //         p2++;
        //     }
        //     i++;
        // }
        // while (p2 != nums2.end())
        // {
        //     nums1[i] = *p2;
        //     p2++;
        //     i++;
        // }
        // while (p1 != t1.end())
        // {
        //     nums1[i] = *p1;
        //     p1++;
        //     i++;
        // }
    }
};
// @lc code=end


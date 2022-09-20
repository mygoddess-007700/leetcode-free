/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool hasAlternatingBits(int n)
    {
        // bool isOne = n % 2;
        // n = n >> 1;
        // while (n != 0)
        // {
        //     bool t = n % 2;
        //     if (t != isOne)
        //     {
        //         isOne = t;
        //     }
        //     else
        //     {
        //         return false;
        //     }
        //     n = n >> 1;
        // }
        // return true;
        long t = n ^ (n >> 1);
        return ((t & (t + 1)) == 0);
    }
};
// @lc code=end


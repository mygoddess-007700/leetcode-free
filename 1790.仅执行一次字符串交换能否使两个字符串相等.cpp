/*
 * @lc app=leetcode.cn id=1790 lang=cpp
 *
 * [1790] 仅执行一次字符串交换能否使两个字符串相等
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        int left = -1;
        int right = -1;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == s2[i]) continue;
            if (left == -1)
            {
                left = i;
                continue;
            }
            if (right == -1)
            {
                right = i;
                continue;
            }
            return false;
        }
        if (left == -1 && right == -1) return true;
        if (left == -1 || right == -1) return false;
        if (s1[left] == s2[right] && s1[right] == s2[left]) return true;
        else return false;
    }
};
// @lc code=end


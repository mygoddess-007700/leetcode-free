/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string s)
    {
        int n = s.length();
        int first = 0;
        int second = n - 1;
        char t;
        while (first < second)
        {
            while (first < n && (!((s[first] >= 'a' && s[first] <= 'z') || (s[first] >= 'A' && s[first] <= 'Z'))))
            {
                first++;
            }
            while (second >= 0 && (!((s[second] >= 'a' && s[second] <= 'z') || (s[second] >= 'A' && s[second] <= 'Z'))))
            {
                second--;
            }
            if (first < second)
            {
                t = s[first];
                s[first] = s[second];
                s[second] = t;
            }
            first++;
            second--;
        }
        return s;
    }
};
// @lc code=end


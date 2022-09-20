/*
 * @lc app=leetcode.cn id=1576 lang=cpp
 *
 * [1576] 替换所有的问号
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    string modifyString(string s)
    {
        string t = "aa";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '?')
            {
                if (i == 0)
                {
                    t[0] = '?';
                    t[1] = s[i+1];
                }
                else if (i == s.length() - 1)
                {
                    t[0] = s[i-1];
                    t[1] = '?';
                }
                else
                {
                    t[0] = s[i-1];
                    t[1] = s[i+1];
                }
                char c = 'a';
                while (c == t[0] || c == t[1])
                {
                    c++;
                }
                s[i] = c;
            }
        }
        return s;
    }
};
// @lc code=end


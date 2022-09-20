/*
 * @lc app=leetcode.cn id=1614 lang=cpp
 *
 * [1614] 括号的最大嵌套深度
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    int maxDepth(string s)
    {
        int maxNum = 0;
        int curNum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                curNum++;
            }
            if (s[i] == ')')
            {
                curNum--;
            }
            maxNum = max(maxNum, curNum);
        }
        return maxNum;
    }
};
// @lc code=end


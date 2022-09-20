/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber)
    {
        string ts = "";
        if (columnNumber < 27)
        {
            ts += 'A' - 1 + columnNumber;
            return ts;
        }
        
        stack<char> s;
        while (columnNumber > 26)
        {
            if (columnNumber % 26 == 0)
            {
                s.push('Z');
                columnNumber = columnNumber / 26 - 1;
            }
            else
            {
                s.push('A' - 1 + (columnNumber % 26));
                columnNumber /= 26;
            }
        }
        ts += 'A' - 1 + columnNumber;
        while (!s.empty())
        {
            char t = s.top();
            s.pop();
            ts += t;
        }
        return ts;
    }
};
// @lc code=end


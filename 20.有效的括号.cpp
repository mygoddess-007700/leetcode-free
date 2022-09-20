/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st;
        char t;
        for (char & c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                t = st.top();
                if (t == '(')
                {
                    if (c != ')')
                    {
                        return false;
                    }
                }
                else if (t == '[')
                {
                    if (c != ']')
                    {
                        return false;
                    }
                }
                else if (t == '{')
                {
                    if (c != '}')
                    {
                        return false;
                    }
                }
                st.pop();
            }
        }
        if (st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end


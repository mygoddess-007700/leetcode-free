/*
 * @lc app=leetcode.cn id=856 lang=cpp
 *
 * [856] 括号的分数
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    int scoreOfParentheses(string s) {
        //计算最终负数和
        // int n = s.length();
        // int num = 1;
        // int val = 0;
        // int ans = 0;
        // for (int i = 1; i < n; i++)
        // {
        //     if (s[i] == '(')
        //     {
        //         if (s[i-1] != ')')
        //         {
        //             num++;
        //         }
        //     }
        //     else
        //     {
        //         if (s[i-1] == ')')
        //         {
        //             num--;
        //         }
        //         else
        //         {
        //             ans += pow(2, num-1);
        //         }
        //     }
        // }
        // return ans;

        //栈
        stack<int> st;
        st.push(0);
        for (auto & t : s)
        {
            if (t == '(')
            {
                st.push(0);
            }
            else
            {
                int num = max(1, 2 * st.top());
                st.pop();
                st.top() += num;
            }
        }
        return st.top();
    }
};
// @lc code=end


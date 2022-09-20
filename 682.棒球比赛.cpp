/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& ops)
    {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < ops.size(); i++)
        {
            string s = ops[i];
            if (s == "+")
            {
                int x2 = st.top();
                st.pop();
                int x1 = st.top();
                int t = x1 + x2;
                st.push(x2);
                st.push(t);
                ans += t;
            }
            else if (s == "D")
            {
                int x = st.top();
                st.pop();
                int t = x * 2;
                st.push(x);
                st.push(t);
                ans += t;
            }
            else if (s == "C")
            {
                int x = st.top();
                st.pop();
                ans -= x;
            }
            else
            {
                int t = stoi(s);
                st.push(t);
                ans += t;
            }
        }
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    void BackTrack(vector<string> & ans, string & s, int len, int left, int right)
    {
        if (s.length() == len * 2)
        {
            ans.push_back(s);
            return;
        }
        if (left < len)
        {
            s.push_back('(');
            BackTrack(ans, s, len, left+1, right);
            s.pop_back();
        }
        if (right < left)
        {
            s.push_back(')');
            BackTrack(ans, s, len, left, right+1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string s;
        BackTrack(ans, s, n, 0, 0);
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int num = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ')')
            {
                if (num > 0) num--;
                else ans++;
            }
            else num++;
        }
        
        return ans+num;
    }
};
// @lc code=end


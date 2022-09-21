/*
 * @lc app=leetcode.cn id=1374 lang=cpp
 *
 * [1374] 生成每种字符都是奇数个的字符串
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<cstring>
using namespace std;
class Solution {
public:
    string generateTheString(int n)
    {
        string ans = "";
        if (n % 2 == 0)
        {
            for (int i = 0; i < n-1; i++)
            {
                ans.append("a");
            }
            ans.append("b");
            return ans;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                ans.append("a");
            }
            return ans;
        }
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
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
    string simplifyPath(string path)
    {
        vector<string> ss;
        int len = path.length();
        int i = 1, j = 1;
        while (i < len)
        {
            if (path[i] == '/')
            {
                i++;
                continue;
            }
            j = i + 1;
            while (j < len && path[j] != '/')
            {
                j++;
            }
            string item = path.substr(i, j - i);
            if (item == "..")
            {
                if (!ss.empty())
                {
                    ss.pop_back();
                }
            }
            else if (item != ".")
            {
                ss.push_back(item);
            }
            i = j + 1;
        }
        if (ss.empty())
        {
            return "/";
        }
        string ans;
        for (auto &t : ss)
        {
            ans += "/";
            ans += t;
        }
        return ans;
    }
};
// @lc code=end

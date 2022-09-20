/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> t;
        int n = s.length();
        for (char & c : s)
        {
            t[c]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (t[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
        // int index = 0;
        // int num = s.length();
        // unordered_map<char, int> t;
        // for (int i = 0; i < num; i++)
        // {
        //     t[s[i]]++;
        //     while (t[s[index]] > 1)
        //     {
        //         index++;
        //         if (index == num)
        //         {
        //             return -1;
        //         }
        //     }
        // }
        // return index;
    }
};
// @lc code=end


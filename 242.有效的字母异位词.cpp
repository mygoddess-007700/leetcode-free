/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        vector<int> word(26, 0);
        for (char & t1 : s)
        {
            word[t1 - 'a']++;
        }
        for (char & t2 : t)
        {
            if (--word[t2 - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end


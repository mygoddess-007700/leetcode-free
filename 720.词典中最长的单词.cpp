/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    static bool Tmp(const string & i, const string & j)
    {
        return i.length() != j.length() ? i.length() < j.length() : i > j;
    }

    string longestWord(vector<string>& words)
    {
        sort(words.begin(), words.end(), &Tmp);
        string ans = "";
        unordered_set<string> s;
        s.emplace("");
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            if (s.count(words[i].substr(0, words[i].length()-1)))
            {
                ans = words[i];
                s.emplace(ans);
            }
        }
        return ans;
    }
};
// @lc code=end


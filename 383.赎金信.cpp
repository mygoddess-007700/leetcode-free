/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (magazine.size() < ransomNote.size())
        {
            return false;
        }
        vector<int> word(26, 0);
        for (char & t1 : magazine)
        {
            word[t1 - 'a']++;
        }
        for (char & t2 : ransomNote)
        {
            if (--word[t2 - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
        // unordered_map<char, int> hashmap;
        // for (char & t1 : magazine)
        // {
        //     hashmap[t1]++;
        // }
        // for (char & t2 : ransomNote)
        // {

        //     if (hashmap[t2] == 0)
        //     {
        //         return false;
        //     }
        //     else
        //     {
        //         hashmap[t2]--;
        //     }
        // }
        // return true;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=1629 lang=cpp
 *
 * [1629] 按键持续时间最长的键
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed)
    {
        vector<int> word(26, 0);
        int n = releaseTimes.size();
        word[keysPressed[0] - 'a'] = releaseTimes[0];
        for (int i = 1; i < n; i++)
        {
            int t = releaseTimes[i] - releaseTimes[i-1];
            word[keysPressed[i] - 'a'] = max(t, word[keysPressed[i] - 'a']);
        }
        char ans = 'a';
        int ansT = 0;
        for (int i = 25; i >= 0; i--)
        {
            if (word[i] > ansT)
            {
                ans = 'a' + i;
                ansT = word[i];
            }
        }
        return ans;
    }
};
// @lc code=end


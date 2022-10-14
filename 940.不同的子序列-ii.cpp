/*
 * @lc app=leetcode.cn id=940 lang=cpp
 *
 * [940] 不同的子序列 II
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> g(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int t = 1;
            for (int j = 0; j < 26; j++)
            {
                t = (t + g[j]) % MOD;
            }
            g[(int)(s[i]-'a')] = t;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            ans = (ans + g[i]) % MOD;
        }
        return ans;
    }

    constexpr static int MOD = (int) 1e9 + 7;
};
// @lc code=end


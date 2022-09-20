/*
 * @lc app=leetcode.cn id=2028 lang=cpp
 *
 * [2028] 找出缺失的观测数据
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n)
    {
        int num = rolls.size();
        int all = mean * (num + n);
        for (int i = 0; i < num; i++)
        {
            all -= rolls[i];
        }
        int t = 0;
        while (t * n < all)
        {
            t++;
        }
        vector<int> ans;
        bool isOk = false;
        if (t > 6)
        {
            return ans;
        }
        if (t == 1)
        {
            if (t * n > all)
            {
                return ans;
            }
        }
        while (all > 0)
        {
            if (all == (n - ans.size()) * (t - 1))
            {
                isOk = true;
            }
            if (all >= t && isOk == false)
            {
                all -= t;
                ans.emplace_back(t);
                continue;
            }
            ans.emplace_back(t-1);
            all -= (t-1);
        }
        cout<<ans.size();
        return ans;

    }
};
// @lc code=end


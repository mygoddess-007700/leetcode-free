/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int money = 0;
        int minMoney = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            money = max(money, prices[i] - minMoney);
            minMoney = min(minMoney, prices[i]);
        }
        return money;
        // int money = 0;
        // for (int i = 0; i < prices.size(); i++)
        // {
        //     for (int j = i; j < prices.size(); j++)
        //     {
        //         money = max(money, prices[j] - prices[i]);
        //     }
        // }
        // return money;
    }
};
// @lc code=end


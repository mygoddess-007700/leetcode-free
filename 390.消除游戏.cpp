/*
 * @lc app=leetcode.cn id=390 lang=cpp
 *
 * [390] 消除游戏
 */

// @lc code=start
class Solution {
public:
    int lastRemaining(int n)
    {
        int a1 = 1;
        int num = n;
        int step = 1;
        int k = 0;
        while (num > 1)
        {
            if (k % 2 == 0)
            {
                a1 = a1 + step;
            }
            if (k % 2 == 1)
            {
                a1 = (num % 2 == 0) ? a1 : a1 + step;
            }
            k++;
            num = num >> 1;
            step = step << 1;
        }
        return a1;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
        {
            return 0;
        }
        int s = 0;
        for (int i = 3; i < n; i++)
        {
            int x = 2;
            while (x < sqrt((float)i)+1)
            {
                if (i % x == 0)
                {
                    s++;
                    break;
                }
                x++;
            }
        }
        s = s + 1;
        return (n-1-s);
    }
};
// @lc code=end


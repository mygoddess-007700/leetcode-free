/*
 * @lc app=leetcode.cn id=1175 lang=cpp
 *
 * [1175] 质数排列
 */

// @lc code=start
// #include <iostream>
// #include <string>
// #include <stack>
// #include <cmath>
// using namespace std;
class Solution {
public:
    int numPrimeArrangements(int n)
    {
        int s = 0;
        for (int i = 2; i <= n; i++)
        {
            int x = 2;
            while (x <= sqrt((float)i)+1)
            {
                if (i % x == 0)
                {
                    s++;
                    break;
                }
                x++;
            }
        }
        s++;
        long long sum = 0;
        long long t = 1;
        for (int i = s; i > 1; i--)
        {
            t = t * i;
        }
        sum += t;
        t = 1;
        s = n - s;
        for (int i = s; i > 1; i--)
        {
            t = t * i;
        }
        sum = t * sum;
        return (sum % ((long)pow(10, 9) + 7));
    }
};
// @lc code=end


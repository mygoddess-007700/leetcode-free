/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        //滑动窗口+暴力
        // int len  = code.size();
        // if (k == 0)
        // {
        //     vector<int> vec(len, 0);
        //     return vec;
        // }
        // int kAbs = abs(k);
        // if (len == 1)
        // {
        //     code[0] = kAbs * code[0];
        //     return code;
        // }
        // vector<int> vec;
        // for (int i = 0; i < len; i++)
        // {
        //     int sum = 0;
        //     for (int j = 0; j < kAbs; j++)
        //     {
        //         sum += code[(i+j+1) % len];
        //     }
        //     vec.push_back(sum);
        // }
        // if (k > 0)
        // {
        //     return vec;
        // }
        // else
        // {
        //     int t = len - kAbs%len - 1;
        //     for (int i = t; i < t + len; i++)
        //     {
        //         int index = i % len;
        //         code[i - t] = vec[index];
        //     }
        //     return code;
        // }

        //前缀和
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0)
        {
            return ans;
        }
        vector<int> sum(2*n + 1, 0);
        for (int i = 1; i <= 2*n; i++)
        {
            sum[i] = sum[i-1] + code[(i-1)%n];
        }
        if (k > 0)
        {
            for (int i = 1; i <= n; i++)
            {
                ans[i-1] = sum[i+k] - sum[i];
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                ans[i-1] = sum[i+n-1] - sum[i+n-1+k];
            }
        }
        return ans;
    }
};
// @lc code=end


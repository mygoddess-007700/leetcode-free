/*
 * @lc app=leetcode.cn id=891 lang=cpp
 *
 * [891] 子序列宽度之和
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
const static int N = 100001, MOD = 1e9 + 7;
public:
    int sumSubseqWidths(vector<int>& nums) {
        long long k[N];
        k[0] = 1;
        for (int i = 1; i < N; i++) {
            k[i] = (2 * k[i-1]) % MOD;
        }

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += k[i] * nums[i] % MOD;
            ans %= MOD;
            ans -= (k[n - 1 - i] * nums[i]) % MOD;
            ans %= MOD;
        }

        return ans;
    }
};
// @lc code=end


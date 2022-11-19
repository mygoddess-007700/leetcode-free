/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int ans = 0;
        int t = 0;
        for (int i = 0; i < n; i++) {
            t += gain[i];
            ans = max(ans, t);
        }
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n)
    {
        vector<int> ans;
        ans.push_back(0);
        int len = 1;
        while (n-- > 0)
        {
            for (int i = len-1; i >= 0; i--)
            {
                ans[i] = ans[i] << 1;
                ans.push_back(ans[i] + 1);
            }
            len *= 2;
        }
        return ans;
    }
};
// @lc code=end


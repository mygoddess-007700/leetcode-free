/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
class Solution
{
public:
    int rotatedDigits(int n)
    {
        //枚举遍历
        // int ans = 0;
        // for (int i = 1; i <= n; ++i) {
        //     string num = to_string(i);
        //     bool valid = true, diff = false;
        //     for (char ch: num) {
        //         if (check[ch - '0'] == -1) {
        //             valid = false;
        //         }
        //         else if (check[ch - '0'] == 1) {
        //             diff = true;
        //         }
        //     }
        //     if (valid && diff) {
        //         ++ans;
        //     }
        // }
        // return ans;

        //动态规划+记忆化搜索
        vector<int> pos;
        while (n)
        {
            pos.push_back(n % 10);
            n = n / 10;
        }
        reverse(pos.begin(), pos.end());
        memset(memo, -1, sizeof(memo));
        n = pos.size();
        function<int(int, bool, bool)> dfs = [&](int index, bool bound, bool diff) -> int
        {
            if (n == index)
                return diff;
            //返回当前算过的状态，深度优先搜索
            if (memo[index][bound][diff] != -1)
                return memo[index][bound][diff];
            int cur = 0;
            for (int i = 0; i <= (bound ? pos[index] : 9); i++)
            {
                if (check[i] != -1)
                {
                    cur += dfs(index + 1, bound && (pos[index] == i), diff || (check[i] == 1));
                }
            }
            return memo[index][bound][diff] = cur;
        };
        return dfs(0, true, false);
    }

private:
    static constexpr int check[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
    int memo[5][2][2];
};
// @lc code=end

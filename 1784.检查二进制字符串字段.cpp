/*
 * @lc app=leetcode.cn id=1784 lang=cpp
 *
 * [1784] 检查二进制字符串字段
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    bool checkOnesSegment(string s) {
        bool isOne = false;
        int n = s.length();
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                if (!isOne)
                {
                    num++;
                }
                isOne = true;
            }
            else
            {
                isOne = false;
            }
        }
        if (num <= 1) return true;
        else return false;
    }
};
// @lc code=end


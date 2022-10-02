/*
 * @lc app=leetcode.cn id=777 lang=cpp
 *
 * [777] 在LR字符串中交换相邻字符
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    bool canTransform(string start, string end) {
        int p1 = 0, p2 = 0;
        int n = start.length();
        while (true)
        {
            while (p1 < n && start[p1] == 'X') p1++;
            while (p2 < n && end[p2] == 'X') p2++;
            if (p1 >= n && p2 >= n) return true;
            if (p1 >= n || p2 >= n || start[p1] != end[p2]) return false;
            if ((start[p1] == 'L' && p1 < p2) || (end[p2] == 'R' && p2 < p1)) return false;
            p1++; p2++;
        }
    }
};
// @lc code=end


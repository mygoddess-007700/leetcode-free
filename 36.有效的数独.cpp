/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int line[10]{0}, row[10]{0}, block[10]{0};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char c = board[i][j];
                if (c == '.')
                {
                    continue;
                }
                int x = c - '0';
                int bNum = i / 3 * 3 + j / 3;
                if ((line[i] >> x) & 1 || (row[j] >> x) & 1 || (block[bNum] >> x) & 1)
                {
                    return false;
                }
                line[i] |= (1 << x);
                row[j] |= (1 << x);
                block[bNum] |= (1 << x);
            }
        }
        return true;
    }
};
// @lc code=end


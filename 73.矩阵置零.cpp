/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int l = matrix.size();
        int r = matrix[0].size();
        bool lineB = false, rowB = false;
        for (int j : matrix[0])
        {
            if (j == 0)
            {
                lineB = true;
            }
        }
        for (int i = 0; i < l; i++)
        {
            if (matrix[i][0] == 0)
            {
                rowB = true;
            }
        }
        for (int i = 1; i < l; i++)
        {
            for (int j = 1; j < r; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < l; i++)
        {
            for (int j = 1; j < r; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (lineB)
        {
            for (int j = 0; j < r; j++)
            {
                matrix[0][j] = 0;
            }
        }
        if (rowB)
        {
            for (int i = 0; i < l; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
// @lc code=end


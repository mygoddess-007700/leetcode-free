/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
    {
        int number = mat.size() * mat[0].size();
        int line;
        int row;
        if (r * c != number)
        {
            return mat;
        }
        vector<vector<int>> newMat(r, vector<int>(c));
        for (int i = 0; i < mat.size(); i ++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                int t = i * mat[0].size() + j;
                line = t / c;
                row = t % c;
                newMat[line][row] = mat[i][j];
            }
        }
        return newMat;
    }
};
// @lc code=end


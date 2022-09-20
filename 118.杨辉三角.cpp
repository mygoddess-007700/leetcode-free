/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> generation;
        generation.push_back(vector<int>(1));
        generation[0][0] = 1;
        int number = 1;
        for (int i = 1; i < numRows; i++)
        {
            number++;
            generation.push_back(vector<int>(number));
            for (int j = 0; j < number; j++)
            {
                if (j == 0)
                {
                    generation[i][j] = generation[i-1][j];
                }
                else if (j == number-1)
                {
                    generation[i][j] = generation[i-1][number-2];
                }
                else
                {
                    generation[i][j] = generation[i-1][j-1] + generation[i-1][j];
                }
            }
        }
        return generation;
    }
};
// @lc code=end


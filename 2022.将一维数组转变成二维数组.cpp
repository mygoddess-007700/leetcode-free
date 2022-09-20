/*
 * @lc app=leetcode.cn id=2022 lang=cpp
 *
 * [2022] 将一维数组转变成二维数组
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n)
    {
        /*
        vector<vector<int>> array(m, vector<int>(n, 0));
        if (original.size() != m * n)
        {
            vector<vector<int>> t;
            return t;
        }
        vector<vector<int>>::iterator p1;
        vector<int>::iterator p2;

        int t = 0;
        for (p1 = array.begin(); p1 != array.end(); p1++)
        {
            for (p2 = p1->begin(); p2 != p1->end(); p2++)
            {
                *p2 = original[t];
                t++;
            }
        }
        return array;
        */
       vector<vector<int>> array;
       if (original.size() != m * n)
       {
           return array;
       }

       for (auto t = original.begin(); t != original.end(); t += n)
       {
           array.emplace_back(t, t+n);
       }

       return array; 
    }
};
// @lc code=end


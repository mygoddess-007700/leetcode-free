/*
 * @lc app=leetcode.cn id=1620 lang=cpp
 *
 * [1620] 网络信号最好的坐标
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int getSD(const vector<int> & c, const vector<int> & tower)
    {
        return (tower[0] - c[0]) * (tower[0] - c[0]) + (tower[1] - c[1]) * (tower[1] - c[1]);
    }

    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int xMax = 0, yMax = 0;
        for (auto && tower: towers)
        {
            int x = tower[0], y = tower[1];
            yMax = max(yMax, y);
            xMax = max(xMax, x);
        }
        int cy = 0, cx = 0;
        int maxQ = 0;
        for (int x = 0; x <= xMax; x++)
        {
            for (int y = 0; y <= yMax; y++)
            {
                vector c = {x, y};
                int q = 0;
                for (auto && tower: towers)
                {
                    int sD = getSD(c, tower);
                    if (sD <= radius * radius)
                    {
                        double distance = sqrt((double)sD);
                        q += floor((double)tower[2] / (1+distance));
                    }
                }
                if (q > maxQ)
                {
                    cx = x;
                    cy = y;
                    maxQ = q;
                }
            }  
        }
        
        return {cx, cy};
    }
};
// @lc code=end


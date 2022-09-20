/*
 * @lc app=leetcode.cn id=1036 lang=cpp
 *
 * [1036] 逃离大迷宫
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    static constexpr int EDGE = 1e6;
    unordered_set<long long> bl;
    int MAX = 1e5;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    long BASE = 12322;
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target)
    {
        for (vector<int> & v : blocked)
        {
            bl.insert(v[0] * BASE + v[1]);
        }
        int n = blocked.size();
        MAX = n * (n-1) /2;
        return (Check(source, target) && Check(target, source));
    }

    bool Check(vector<int> & s, vector<int> & t)
    {
        unordered_set<long long> vis;
        queue<pair<int, int>> q;
        q.push({s[0], s[1]});
        vis.insert(s[0] * BASE + s[1]);
        while (!q.empty() && vis.size() <= MAX)
        {
            pair<int, int> tp = q.front();
            int x = tp.first, y = tp.second;
            if (x == t[0] && y == t[1])
            {
                return true;
            }
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int tx = x + dir[i][0];
                int ty = y + dir[i][1];
                if (tx < 0 || tx >= EDGE || ty < 0 || ty >= EDGE)
                {
                    continue;
                }
                if (bl.count(tx * BASE + ty))
                {
                    continue;
                }
                if (vis.count(tx * BASE + ty))
                {
                    continue;
                }
                vis.insert(tx * BASE + ty);
                q.push({tx, ty});
            }
        }
        return vis.size() > MAX;
    }
};
// @lc code=end


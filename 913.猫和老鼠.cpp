/*
 * @lc app=leetcode.cn id=913 lang=cpp
 *
 * [913] 猫和老鼠
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<cstring>
using namespace std;
const int MOUSE_WIN = 1;
const int CAT_WIN = 2;
const int DRAW = 0;
const int MAXNUM = 51;
class Solution
{
private:
    int n;
    int dp[MAXNUM][MAXNUM][MAXNUM * 2];
    vector<vector<int>> graph;
public:
    void GetNextResult(int mouse, int cat, int turn)
    {
        int curMove = (turn % 2 == 0) ? mouse : cat;
        int defaultResult = (curMove == mouse) ? CAT_WIN : MOUSE_WIN;
        int result = defaultResult;
        for (int next : graph[curMove])
        {
            if (curMove == cat && next == 0)
            {
                continue;
            }
            int nextMouse = (curMove == mouse) ? next : mouse;
            int nextCat = (curMove == cat) ? next : cat;
            int nextResult = GetResult(nextMouse, nextCat, turn + 1);
            if (nextResult != defaultResult)
            {
                result = nextResult;
                if (result != DRAW)
                {
                    break;
                }
            }
        }
        dp[mouse][cat][turn] = result;
    }

    int GetResult(int mouse, int cat, int turn)
    {
        if (turn == n * 2)
        {
            return DRAW;
        }
        if (dp[mouse][cat][turn] < 0)
        {
            if (mouse == 0)
            {
                dp[mouse][cat][turn] = MOUSE_WIN;
            }
            else if(mouse == cat)
            {
                dp[mouse][cat][turn] = CAT_WIN;
            }
            else
            {
                GetNextResult(mouse, cat, turn);
            }
        }
        return dp[mouse][cat][turn];
    }

    int catMouseGame(vector<vector<int>>& graph)
    {
        this->n = graph.size();
        this->graph = graph;
        memset(dp, -1, sizeof(dp));
        return GetResult(1, 2, 0);
    }
};
// @lc code=end


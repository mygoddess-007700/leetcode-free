/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
    int he[20001];
    int e[20001];
    int ne[20000001];
    int color[2001];

    int index;
public:
    void add(int a, int b)
    {
        e[index] = b;
        ne[index] = he[a];
        he[a] = index;
        index++;
    }

    bool dfs(int u, int c, int * color)
    {
        color[u] = c;
        for (int i = he[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (c == color[j]) return false;
            if (color[j] == 0 && !dfs(j, 3-c, color)) return false;
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int n1 = dislikes.size();
        for (int i = 0; i < 2001; i++)
        {
            he[i] = -1;
        }
        for (int i = 0; i < n1; i++)
        {
            int a = dislikes[i][0], b = dislikes[i][1];
            add(a, b);
            add(b, a);
        }

        for (int i = 1; i <= n; i++)
        {
            //没染过色的才需要染色
            if (color[i] != 0) continue;
            if (!dfs(i, 1, color)) return false;
        }
        return true;
    }
};
// @lc code=end


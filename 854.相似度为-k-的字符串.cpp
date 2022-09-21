/*
 * @lc app=leetcode.cn id=854 lang=cpp
 *
 * [854] 相似度为 K 的字符串
 */

// @lc code=start
// 广度优先搜索+剪枝+AStar算法的应用
#include <string>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;
class Solution {
    string t;
    int len;
    int f(const string & a) {
        int num = 0;
        for (int i = 0; i < len; i++) {
            if (a[i] != t[i]) num++;
        }
        return (num + 1) >> 1;
    }
public:
    int kSimilarity(string s1, string s2) {
        if (s1 == s2) return 0;
        len = s1.length();
        t = s2;
        unordered_map<string, int> map;
        auto cmp = [&](const string& a, const string& b) {
            int z1 = map[a];
            int z2 = map[b];
            int d1 = f(a);
            int d2 = f(b);
            return ((d1+z1)-(d2+z2)) >= 0;
        };
        priority_queue<string, vector<string>, function<bool(const string&, const string&)>> pq(cmp);
        map.emplace(s1, 0);
        pq.emplace(s1);
        while (!pq.empty()) {
            string s = pq.top();
            int step = map[s];
            pq.pop();
            int i = 0;
            while (s[i] == t[i] && i < len) i++;
            // if (i == len) return step;
            for (int j = i+1; j < len; j++) {
                if (s[j] == t[i] && s[j] != t[j])
                {
                    swap(s[i], s[j]);
                    if (map.count(s) && map[s] <= step+1) continue;
                    if (s == t) return step+1;
                    map[s] = step+1;
                    pq.emplace(s);
                    swap(s[i], s[j]);
                }
            }
        }
        return -1;
    }
};
// @lc code=end


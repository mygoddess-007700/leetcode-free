/*
 * @lc app=leetcode.cn id=1640 lang=cpp
 *
 * [1640] 能否连接形成数组
 */

// @lc code=start
//哈希表存储
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> map;
        for (int i = 0; i < arr.size(); ++i) {
            map[arr[i]] = i;
        }
        for (int i = 0; i < pieces.size(); ++i) {
            int n = pieces[i].size();
            int index = -1;
            for (int j = 0; j < n; ++j) {
                if (j == 0) if (!map.count(pieces[i][j])) return false;
                else index = map[pieces[i][j]];
                else {
                    if (map.count(pieces[i][j]) & map[pieces[i][j]] == index+1) index = map[pieces[i][j]];
                    else return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end


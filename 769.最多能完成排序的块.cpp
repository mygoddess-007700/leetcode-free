/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> t(arr);
        sort(t.begin(), t.end());
        int mi = t[0], ma = t[0];
        int ans = 0;
        int hasMin = true;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == mi) hasMin = true;
            ma = max(ma, arr[i]);
            if (hasMin && t[i] == ma) 
            {
                ans++;
                if (i == n-1)
                {
                    break;
                }
                else
                {
                    mi = t[i+1];
                    hasMin = false;
                }
            }
        } 
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // int n = fruits.size();
        // if (n == 1) return 1;

        // int basket[2];
        // basket[0] = -1;
        // basket[1] = fruits[0];

        // int ans = 0;
        // int t = 0;
        // int lastFruit = fruits[0];
        // int last = 0;

        // int i;
        // for (i = 0; i < n; i++)
        // {
        //     if (fruits[i] == fruits[0])
        //     {
        //         t++;
        //         last++;
        //     }
        //     else
        //     {
        //         break;
        //     }
        // }
        
        // for (; i < n; i++)
        // {
        //     if (fruits[i] != basket[0] && fruits[i] != basket[1])
        //     {
        //         basket[0] = lastFruit;
        //         basket[1] = fruits[i];
        //         lastFruit = fruits[i];

        //         ans = max(t, ans);
        //         t = last + 1;
        //         last = 1;
        //     }
        //     else
        //     {
        //         if (fruits[i] == lastFruit)
        //         {
        //             last++;
        //         }
        //         else
        //         {
        //             lastFruit = fruits[i];
        //             last = 1;
        //         }
        //         t++;
        //     }
        // }
        // return max(t, ans);

        //滑动窗口
        int n = fruits.size();
        int left = 0;
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int right = 0; right < n; right++)
        {
            cnt[fruits[right]]++;
            while (cnt.size() > 2)
            {
                auto it = cnt.find(fruits[left]);
                if (--it->second == 0)
                {
                    cnt.erase(it);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        //多路归并
        // vector<int> nums(n, 0);
        // int s1{}, s2{}, s3{};
        // nums[0] = 1;
        // for (int i = 1; i < n; i++)
        // {
        //     nums[i] = min(2 * nums[s1], min(3 * nums[s2], 5 * nums[s3]));
        //     if (nums[i] == 2 * nums[s1]) s1++;
        //     if (nums[i] == 3 * nums[s2]) s2++;
        //     if (nums[i] == 5 * nums[s3]) s3++;
        // }
        // return nums[n-1];
        //优先队列+哈希表去重
        int t[3] = {2, 3, 5};
        priority_queue<long long, vector<long long>, greater<>> q;
        unordered_set<long long> s;
        q.push(1);
        s.emplace(1);
        while (!q.empty())
        {
            --n;
            if (n == 0) break;
            long long m = q.top();
            q.pop();
            for (int & i: t)
            {
                if (s.count(m * i)) continue;
                q.push(m * i);
                s.emplace(m * i);
            }
        }
        return q.top();
    }
};
// @lc code=end


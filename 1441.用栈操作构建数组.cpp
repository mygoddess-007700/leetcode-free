/*
 * @lc app=leetcode.cn id=1441 lang=cpp
 *
 * [1441] 用栈操作构建数组
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int num = target.size();
        vector<string> ans;
        int index = 1;
        for (int i = 0; i < num; i++)
        {
            while (index != target[i])
            {
                ans.push_back("Push");
                ans.push_back("Pop");
                index++;
            }
            ans.push_back("Push");
            index++;
        }        
        return ans;
    }
};
// @lc code=end


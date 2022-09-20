/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
    {
        unordered_map<string, int> map;

        for (int i = 0; i < list1.size(); i++)
        {
            map[list1[i]] = i;
        }

        vector<string> ans;
        int index = -1;
        for (int j = 0; j < list2.size(); j++)
        {
            if (!ans.empty())
            {
                if (j > index)
                {
                    break;
                }
            }
            
            if (map.count(list2[j]))
            {
                if (ans.empty())
                {
                    ans.emplace_back(list2[j]);
                    index = j + map[list2[j]];
                }
                else if (index > j + map[list2[j]])
                {
                    ans.clear();
                    ans.emplace_back(list2[j]);
                    index = j + map[list2[j]];
                }
                else if (index == j + map[list2[j]])
                {
                    ans.emplace_back(list2[j]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end


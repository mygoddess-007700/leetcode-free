/*
 * @lc app=leetcode.cn id=1694 lang=cpp
 *
 * [1694] 重新格式化电话号码
 */

// @lc code=start
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    string reformatNumber(string number) {
        number.erase(remove(number.begin(), number.end(), ' '), number.end());
        number.erase(remove(number.begin(), number.end(), '-'), number.end());
        int n = number.length();
        vector<string> v;
        int i;
        
        for (i = 0; i < n - 4; i = i+3)
        {
            v.push_back(number.substr(i, 3));
        }
        if ((n - i) == 4)
        {
            v.push_back(number.substr(i, 2));
            v.push_back(number.substr(i+2, 2));
        }
        else if ((n - i) == 3)
        {
            v.push_back(number.substr(i, 3));
        }
        else
        {
            v.push_back(number.substr(i, 2));
        }

        string ans = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            ans = ans + '-' + v[i];
        }
        // for (auto i = v.begin()+1; i != v.begin(); i++)
        // {
        //     ans = ans + "-" + *i;
        // }

        return ans;
    }
};
// @lc code=end


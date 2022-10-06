/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> map;
        for (string & s: cpdomains)
        {
            int index = s.find(' ');
            int num = stoi(s.substr(0, index));
            string domain = s.substr(index+1);
            map[domain] += num;
            for (int i = 0; i < domain.length(); i++)
            {
                if (domain[i] == '.')
                {
                    string t = domain.substr(i+1);
                    map[t] += num;
                }
            }
        }
        vector<string> ans;
        for (auto & m: map)
        {
            ans.push_back(to_string(m.second) + ' ' + m.first);
        }
        return ans;
    }
};
// @lc code=end


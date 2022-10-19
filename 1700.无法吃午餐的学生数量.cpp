/*
 * @lc app=leetcode.cn id=1700 lang=cpp
 *
 * [1700] 无法吃午餐的学生数量
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n1 = students.size(), n2 = sandwiches.size();
        int num0 = 0, num1 = 0;
        for (int i = 0; i < n1; i++)
        {
            if (students[i] == 0) num0++;
            else num1++;
        }
        for (int i = 0; i < n2; i++)
        {
            if (sandwiches[i] == 1)
            {
                if (num1 > 0) num1--;
                else return num0;
            }
            else
            {
                if (num0 > 0) num0--;
                else return num1;
            }
        }
        return num0+num1;
    }
};
// @lc code=end


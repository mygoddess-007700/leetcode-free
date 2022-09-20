/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 *
 * [1185] 一周中的第几天
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year)
    {
        string week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int monthDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        int tDay = 0;
        for (int i = 1971; i < year; i++)
        {
            if ((i % 400 == 0) || ((i % 4 == 0) && (i % 100) != 0))
            {
                tDay += 366;
            }
            else
            {
                tDay += 365;
            }
        }
        if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100) != 0))
        {
            monthDay[1] = 29;
        }
        for (int i = 0; i < month-1; i++)
        {
            tDay += monthDay[i];
        }
        tDay += day;
        return week[(4 + tDay)%7];
    }
};
// @lc code=end


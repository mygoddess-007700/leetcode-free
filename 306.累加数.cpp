/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isAdditiveNumber(string num)
    {
        int n = num.size();
        for (int secondNumBegin = 1; secondNumBegin < n-1; secondNumBegin++)
        {
            if (num[0] == '0' && secondNumBegin != 1)
            {
                break;
            }
            for (int secondNumEnd = secondNumBegin; secondNumEnd < n-1; secondNumEnd++)
            {
                if (num[secondNumBegin] == '0' && secondNumBegin != secondNumEnd)
                {
                    break;
                }
                if (Vaild(num, secondNumBegin, secondNumEnd))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool Vaild(string num, int secondNumBegin, int secondNumEnd)
    {
        int n = num.size();
        int firstNumBegin = 0;
        int firstNumEnd = secondNumBegin - 1;

        while (secondNumEnd <= n-1)
        {
            string thirdNum = StringAdd(num, firstNumBegin, firstNumEnd, secondNumBegin, secondNumEnd);
            int thirdNumBegin = secondNumEnd + 1;
            int thirdNumEnd = secondNumEnd + thirdNum.size();

            if (thirdNumEnd >= n || thirdNum != num.substr(thirdNumBegin, thirdNum.size()))
            {
                break;
            }
            if (thirdNumEnd == n - 1)
            {
                return true;
            }
            firstNumBegin = secondNumBegin;
            firstNumEnd = secondNumEnd;
            secondNumBegin = thirdNumBegin;
            secondNumEnd = thirdNumEnd;
        }
        return false;
    }

    string StringAdd(string num, int firstNumBegin, int firstNumEnd, int secondNumBegin, int secondNumEnd)
    {
        int carry = 0, cur = 0;
        string thirdNum;
        while (secondNumBegin <= secondNumEnd || firstNumBegin <= firstNumEnd || carry != 0)
        {
            cur = carry;
            if (secondNumEnd >= secondNumBegin)
            {
                cur += (num[secondNumEnd] - '0');
                secondNumEnd--;
            }
            if (firstNumEnd >= firstNumBegin)
            {
                cur += (num[firstNumEnd] - '0');
                firstNumEnd--;
            }
            carry = cur / 10;
            cur = cur % 10;
            thirdNum.push_back(cur + '0');
        }
        reverse(thirdNum.begin(), thirdNum.end());
        return thirdNum;
    }
};
// @lc code=end


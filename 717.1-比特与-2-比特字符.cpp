/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1比特与2比特字符
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits)
    {
        if (bits.size() == 1)
        {
            return true;
        }
        if (bits[bits.size() - 2] == 0)
        {
            return true;
        }
        int num = 0;
        for (int i = bits.size() - 2; i >= 0; i--)
        {
            if (bits[i] == 1)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        if (num % 2 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end


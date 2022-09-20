/*
 * @lc app=leetcode.cn id=838 lang=cpp
 *
 * [838] 推多米诺
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.length();
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] == '.')
            {
                continue;
            }
            else if (dominoes[i] == 'R')
            {
                if (dominoes[index] == 'R')
                {
                    for (int j = index + 1; j < i; j++)
                    {
                        dominoes[j] = 'R';
                    }
                }
                index = i;
            }
            else if (dominoes[i] == 'L')
            {
                if (dominoes[index] == '.')
                {
                    for (int j = index; j < i; j++)
                    {
                        dominoes[j] = 'L';
                    }
                }
                else if (dominoes[index] == 'L')
                {
                    for (int j = index + 1; j < i; j++)
                    {
                        dominoes[j] = 'L';
                    }
                }
                else
                {
                    if ((i - index) % 2 == 0)
                    {
                        for (int j = index + 1; j < index + (i - index) / 2; j++)
                        {
                            dominoes[j] = 'R';
                        }
                    }
                    else
                    {
                        for (int j = index + 1; j < index + (i - index) / 2 + 1; j++)
                        {
                            dominoes[j] = 'R';
                        }
                    }
                    for (int j = index + (i - index) / 2 + 1; j < i; j++)
                    {
                        dominoes[j] = 'L';
                    }
                }
                index = i;
            }
        }
        if (dominoes[index] == 'R')
        {
            for (int j = index + 1; j < n; j++)
            {
                dominoes[j] = 'R';
            }
        }
        return dominoes;
    }
};
// @lc code=end


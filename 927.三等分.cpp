/*
 * @lc app=leetcode.cn id=927 lang=cpp
 *
 * [927] 三等分
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int num = 0;
        int n = arr.size();
        for (auto & i: arr)
        {
            if (i == 1) num++; 
        }
        if (num == 0) return {0, 2};
        if (num % 3 != 0) return {-1, -1};
        else num = num / 3;

        int ** data = new int * [3];
        for (int i = 0; i < 3; i++)
        {
            data[i] = new int[num];
        }

        int start = 0;
        int end = 0;
        int ans1 = 0;
        int ans2 = 0;
        int t = 0;
        while (arr[start] != 1) start++;
        for (int i = start, j = 0, f = 0, s = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                data[f][s] = i - j;
                j = i + 1;
                s++;
                if (s >= num)
                {
                    s -= num;
                    f++;
                    if (f == 1)
                    {
                        cout<<i<<endl;
                        ans1 = i;
                    }
                    else if (f == 2)
                    {
                        cout<<i<<endl;
                        ans2 = i;
                    }
                    else if (f >= 3)
                    {
                        end = n - i - 1;
                        cout<<end<<endl;
                        break;
                    }
                }
            }
        }

        for (int i = 1; i < num; i++)
        {
            if (!(data[0][i] == data[1][i] && data[1][i] == data[2][i])) return {-1, -1};
        }

        int l2 = data[1][0];
        int l3 = data[2][0];
        int r3 = end;
        if (l2 < end || l3 < end) return {-1, -1};
        return {ans1 + r3, ans2 + r3 + 1};
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=1608 lang=cpp
 *
 * [1608] 特殊数组的特征值
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<cstring>
#include <cmath>
using namespace std;
class Solution {
void quickSort(vector<int>& nums, int l, int r)
{
    if (r <= l) return;
    int j = partition(nums, l, r);
    quickSort(nums, l, j-1);
    quickSort(nums, j+1, r);
}

int partition(vector<int>& nums, int l, int r)
{
    int i = l, j = r + 1;
    int v = nums[l];
    while (true)
    {
        while (nums[++i] < v) if (i == r) break;
        while (v < nums[--j]) if (j == l) break;
        if (i >= j) break;
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
    int t = nums[l];
    nums[l] = nums[j];
    nums[j] = t;
    return j;
}

int binarySearhch(vector<int>& nums, int key)
{
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        int cmp = compare(key, nums[mid]);
        if (cmp <= 0) r = mid;
        else l = mid + 1;
    }
    return r;
}

int compare(int a, int b)
{
    if (a > b) return 1;
    else if (a < b) return -1;
    else return 0;
}

public:
    int specialArray(vector<int>& nums) {
        int len = nums.size();
        quickSort(nums, 0, len-1);
        int x = min(len, nums[len-1]);
        for (int key = 0; key <= x; key++)
        {
            if (key == len - binarySearhch(nums, key)) return key;
        }
        return -1;
    }
};
// @lc code=end


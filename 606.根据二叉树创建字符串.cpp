/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    string tree2str(TreeNode* root)
    {
        string t = std::to_string(root->val);
        if (root->left != nullptr)
        {
            t = t + "(" + tree2str(root->left) + ")";
        }
        else
        {
            if (root->right != nullptr)
            {
                t = t + "()";
            }
            else
            {
                return t;
            }
        }
        if (root->right != nullptr)
        {
            t = t + "(" + tree2str(root->right) + ")";
        }
        return t;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        // 递归
        // vector<int> ans;
        // VecPreOrder(root, ans);
        // return ans;
        // 迭代
        // vector<int> ans;
        // if (root == nullptr)
        // {
        //     return ans;
        // }
        // stack<TreeNode *> stk;
        // TreeNode * node = root;
        // while (!stk.empty() || node != nullptr)
        // {
        //     while (node != nullptr)
        //     {
        //         ans.emplace_back(node->val);
        //         stk.emplace(node);
        //         node = node->left;
        //     }
        //     node = stk.top();
        //     stk.pop();
        //     node = node->right;
        // }
        // return ans;
        //morris
    }

    // void VecPreOrder(TreeNode* root, vector<int> & ans)
    // {
    //     if (root == nullptr)
    //     {
    //         return;
    //     }
    //     ans.push_back(root->val);
    //     VecPreOrder(root->left, ans);
    //     VecPreOrder(root->right, ans);
    // }
};
// @lc code=end


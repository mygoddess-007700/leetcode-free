/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    TreeNode * _root;

    bool Find(TreeNode* root, int x)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->val == x)
        {
            return true;
        }
        if (x < root->val)
        {
            if (Find(root->left, x))
            {
                return true;
            }
        }
        else
        {
            if (Find(root->right, x))
            {
                return true;
            }
        }
        return false;
    }

    bool FindTarget(TreeNode* root, const int k)
    {
        if (root != nullptr)
        {
            int x = k - root->val;
            
            if (x == root->val)
            {
                
            }
            else if (x < root->val)
            {
                if (Find(_root, x))
                {
                    return true;
                }
            }
            else
            {
                if (Find(_root, x))
                {
                    return true;
                }
            }
            if (FindTarget(root->left, k) || FindTarget(root->right, k))
            {
                return true;
            }
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k)
    {
        _root = root;
        return FindTarget(root, k);
    }
};
// @lc code=end


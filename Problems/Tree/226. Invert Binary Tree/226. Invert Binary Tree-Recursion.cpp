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
//---------------------------------------------
/**
 * @file    226. Invert Binary Tree-Stack-Recursion
 * @brief   使用遞迴 (Implementation using Recursion)
 * @author  BY Huang
 * @date    2025-03-02
 * @version 1.0
 * 
 * @details
 * 本程式提供了一個基於遞迴 (Recursion) 實作，包括：
 * - invertTree
 */
//---------------------------------------------

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==0)
            return 0;
        TreeNode* tmp=root->left;
        root->left=invertTree(root->right);
        root->right=invertTree(tmp);
        return root;

    }
};
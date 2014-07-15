/*
    bluepp
    2014-06-14
    2014-07-16
    May the force be with you!
    
    Problem:    Maximum Depth of Binary Tree
    Source:     https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
    Notes:
    Given a binary tree, find its maximum depth.
    The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

    Solution: Recursion.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return 1 + max(l, r);
    }

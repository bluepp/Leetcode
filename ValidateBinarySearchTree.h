/*
    bluepp
    2014-07-01
    2014-07-30
    2014-08-16
    May the force be with me!
    
 Problem:    Validate Binary Search Tree
 Source:     https://oj.leetcode.com/problems/validate-binary-search-tree/
 Notes:
 Given a binary tree, determine if it is a valid binary search tree (BST).
 Assume a BST is defined as follows:
 The left subtree of a node contains only nodes with keys less than the node's key.
 The right subtree of a node contains only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.

 Solution: Recursion. 1. Add lower & upper bound. O(n)
                      2. Inorder traversal with one additional parameter (value of predecessor). O(n)
 */

    
/* lower, upper bound */    
    bool isValidBST(TreeNode *root) {
        return _isValid(root, INT_MIN, INT_MAX);
    }
    
    bool _isValid(TreeNode *root, int min, int max)
    {
        if (!root) return true;
        if (root->val <= min || root->val >= max) return false;
        
        return _isValid(root->left, min, root->val) && _isValid(root->right, root->val, max);
    }    
    
    
    
/* inorder traversal */    
    bool isValidBST(TreeNode *root) {
        int val = INT_MIN;
        return _isValid(root, val);
    }
    
    bool _isValid(TreeNode *root, int &val)
    {
        if (!root) return true;
        if (root->left && !_isValid(root->left, val)) return false;
        if (root->val <= val) return false;
        
        val = root->val;
        if (root->right && !_isValid(root->right, val)) return false;
        return true;
            
    }

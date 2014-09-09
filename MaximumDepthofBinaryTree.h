/*
    bluepp
    
    2014-06-14
    2014-07-16
    2014-09-09
    
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


/* 2014-09-09, my solution */
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int ret = 0;
        int count = 0;
        
        while (!q.empty())
        {
            TreeNode *pCurr = q.front(); q.pop();
            
            if (pCurr)
            {
                if (pCurr->left) q.push(pCurr->left);
                if (pCurr->right) q.push(pCurr->right);
            }
            else
            {
                count ++;
                if (q.empty()) break;
                q.push(NULL);
            }
            
        }
        
        return count;
    }

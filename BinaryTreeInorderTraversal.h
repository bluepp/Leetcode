/*
    bluepp
    
    2014-06-01
    2014-07-07
    2014-08-06
    2014-09-08
    
    May the force be with me!
    
  
    Problem:    Binary Tree Inorder Traversal

    Source:     http://leetcode.com/onlinejudge#question_94
    Notes:
    Given a binary tree, return the inorder traversal of its nodes' values.
    For example:
    Given binary tree {1,#,2,3},
    1
      \
        2
      /
    3
    return [1,3,2].
    Note: Recursive solution is trivial, could you do it iteratively?

    Solution:  1. Iterative way (stack).   Time: O(n), Space: O(n).
               2. Recursive solution.      Time: O(n), Space: O(n).
               3. Threaded tree (Morris).  Time: O(n), Space: O(1).
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
 
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        TreeNode *pCurr = root;
        vector<int> res;
        
        while (pCurr || !s.empty())
        {
            if (pCurr)
            {
                s.push(pCurr);
                pCurr = pCurr->left;
            }
            else
            {
                pCurr = s.top();
                s.pop();
                res.push_back(pCurr->val);
                pCurr = pCurr->right;
            }
        }
        
        return res;
  
    }
    
    
    /* 2015-07-23, update, Morris */
        vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        TreeNode *pCurr = root;
        while (pCurr)
        {
            if (pCurr->left)
            {
                TreeNode *prev = pCurr->left;
                while (prev->right && prev->right != pCurr)
                {
                    prev = prev->right;
                }
                
                if (prev->right == pCurr)
                {
                    res.push_back(pCurr->val);
                    
                    pCurr = pCurr->right;
                    prev->right = NULL;
                }
                else
                {
                    prev->right = pCurr;
                    pCurr = pCurr->left;
                }
            }
            else
            {
                res.push_back(pCurr->val);
                pCurr = pCurr->right;
            }
        }
        
        return res;
    }
    

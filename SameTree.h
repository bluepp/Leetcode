/*
    bluepp
    2014-06-22
    May the force be with me!
    
   
 Problem:    Same Tree
 Source:     https://oj.leetcode.com/problems/same-tree/
 Notes:
 Given two binary trees, write a function to check if they are equal or not.
 Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

 Solution: recursion.
 */

    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;
        if ((p && !q) || (!p && q))
            return false;
        if (p->val != q->val)
            return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);  
     
    }

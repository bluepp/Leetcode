/*
    bluepp
    2014-06-29
    2014-08-01
    May the force be with me!
    
    
 Problem:    Symmetric Tree
 Source:     https://oj.leetcode.com/problems/symmetric-tree/
 Notes:
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 For example, this binary tree is symmetric:
     1
    / \
   2   2
  / \ / \
 3  4 4  3
 But the following is not:
    1
   / \
  2   2
   \   \
   3    3
 Note:
 Bonus points if you could solve it both recursively and iteratively.

 Solution: 1. Recursive solution 2.Iterative way (queue).
 */
 
/* recursion version */ 
 
    bool isSymmetric(TreeNode *root) {
        if (!root || (!root->left && !root->right))
            return true;
        
        TreeNode *L = root->left , *R = root->right;    
        if (!L || !R) return false;
        if (L->val != R->val) return false;
            
        return _isSymme(L, R);    
    }
    
    bool _isSymme(TreeNode *n1, TreeNode *n2)
    {
        if (!n1 && !n2) return true;
        if (!n1 || !n2) return false;
        if (n1->val != n2->val) return false;
        
        return _isSymme(n1->left, n2->right) && _isSymme(n1->right, n2->left);
    }
    
    
-----------------------
/* iterative */

    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty())
        {
            TreeNode *p1 = q.front(); q.pop();
            TreeNode *p2 = q.front(); q.pop();
            
            if (!p1 && !p2) continue;
            if (!p1 || !p2 ||p1->val != p2->val) return false;
            
            q.push(p1->left);
            q.push(p2->right);
            q.push(p1->right);
            q.push(p2->left);
        }
        
        return true;
    }
    

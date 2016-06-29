/*
  2015-08-27
  bluepp
  May the force be with me!
  
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
https://leetcode.com/problems/closest-binary-search-tree-value/
*/

/* 2016-06-30 */
    int closestValue(TreeNode* root, double target) {
        
        int ret = root->val;
        
        while (root)
        {
            if (abs(ret-root->val) >= abs(root->val-target))
            {
                ret = root->val;
            }
            
            root = target < root->val ? root->left: root->right;
        }
        
        return ret;
        
    }


/* 2016-06-16, update, recursion version*/

    int closestValue(TreeNode* root, double target) {
        
        int a = root->val;
        auto kid = target < a ? root->left : root->right;
        if (!kid) return a;
        
        int b = closestValue(kid, target);
        return abs(a-target) < abs(b-target) ? a : b;
    }

/* iterative version */

    int closestValue(TreeNode* root, double target) {
        
        int ret = root->val;
        
        while (root)
        {
            if ((double)root->val == target)
            {
                return root->val;
            }
            
            if (abs(root->val - target) < abs(ret - target))
            {
                ret = root->val;
            }
            
            if (target < root->val) root = root->left;
            else root = root->right;
          
        }
        
        return ret;
    }    

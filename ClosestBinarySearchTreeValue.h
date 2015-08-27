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

    int closestValue(TreeNode* root, double target) {
            int result=root->val;
            
            while(root){
            if((double)root->val==target)return root->val;
            if(abs((double)root->val-target)<abs(result-target))
                result=root->val;
            if(root->val>target)root=root->left;
            else root=root->right;
        }
        
        return result;
    }

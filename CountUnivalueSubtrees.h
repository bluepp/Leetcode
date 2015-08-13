/*
  2015-08-13
  bluepp
  May the force be with me!
  
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.
https://leetcode.com/problems/count-univalue-subtrees/
*/

    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        
        int count = 0;
        uni_count(root, count);
        return count;
    }
    
    bool uni_count(TreeNode *root, int &count)
    {
        if (!root) return true;
        
        bool l = true, r = true;
        
        if (root->left) l = uni_count(root->left, count) && (root->left->val == root->val);
        if (root->right) r = uni_count(root->right, count) && (root->right->val == root->val);
        
        if (l && r)
        {
            count++;
            return true;
        }
        
        return false;
    }

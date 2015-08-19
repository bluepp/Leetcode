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


/* 2015-08-17, my version */

    int countUnivalSubtrees(TreeNode* root) {
        
        int count = 0;
        _count(root, count);
        return count;
    }
    
    bool _count(TreeNode *root, int &count)
    {
        if (!root)
        {
            count = 0;
            return true;
        }
        
        if (!root->left && !root->right)
        {
            count = 1;
            return true;
        }
        
        int lcount = 0, rcount = 0;
        bool l = _count(root->left, lcount);
        bool r = _count(root->right, rcount);
        
        if (l && r)
        {
            if (root->left && root->left->val != root->val || root->right && root->right->val != root->val)
            {
                count = lcount+rcount;
                return false;
            }
            else
            {
                count = lcount+rcount+1;
                return true;
            }
        }
        else
        {
            count = lcount+rcount;
            return false;
        }
    }




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
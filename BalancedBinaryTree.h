/*
  bluepp
  2014-05-31
  2014-07-06
  2014-08-05
  May the force be with me!
  
  Problem:    Balanced Binary Tree
  Source:     https://oj.leetcode.com/problems/balanced-binary-tree/
  Notes:
  Given a binary tree, determine if it is height-balanced.
  For this problem, a height-balanced binary tree is defined as a binary tree in which 
  the depth of the two subtrees of every node never differ by more than 1.

  Solution: DFS.
 */
 
/* my solution */ 
    bool isBalanced(TreeNode *root) {
        if (!root || !root->left && !root->right) return true;
        
        int l = height(root->left);
        int r = height(root->right);
        if (abs(l-r) > 1) return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int height(TreeNode *root)
    {
        if (!root) return 0;
        
        int l = height(root->left);
        int r = height(root->right);
        return max(l,r) + 1;
    }
 
 
/* others */
    bool isBalanced(TreeNode *root) {
        int height = 0;    
        return isBalanced_help(root, height);    
    }
    
    bool isBalanced_help(TreeNode *root, int &height)
    {
        if (!root)
        {
           return true;
        }
        
        int left_height = 0;
        int right_height = 0;
        
        bool l = isBalanced_help(root->left, left_height);
        bool r = isBalanced_help(root->right, right_height);
        
        height = max(left_height, right_height) + 1;
       
        if (l && r && (abs(left_height - right_height) <= 1))
            return true;
    
       return false;
           
    }


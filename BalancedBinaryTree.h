/*
  bluepp
  2014-05-31
  May the force be with me
  
  Problem:    Balanced Binary Tree
  Source:     http://leetcode.com/onlinejudge#question_110
  Notes:
  Given a binary tree, determine if it is height-balanced.
  For this problem, a height-balanced binary tree is defined as a binary tree in which 
  the depth of the two subtrees of every node never differ by more than 1.

  Solution: DFS.
 */

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


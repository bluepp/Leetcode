/*
  bluepp
  2014-12-09
  May the force be with me!

https://oj.leetcode.com/problems/binary-tree-upside-down/  
Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

For example:
Given a binary tree {1,2,3,4,5},
    1
   / \
  2   3
 / \
4   5
return the root of the binary tree [4,5,2,#,#,3,1].
   4
  / \
 5   2
    / \
   3   1  
   
solution: 1. iteration http://www.danielbit.com/blog/puzzle/leetcode/leetcode-binary-tree-upside-down   
          2. recursion http://bangbingsyb.blogspot.com/2014/11/leetcode-binary-tree-upside-down.html
*/

/* iteration */

    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        
        TreeNode *p = root, *parent = NULL, *parentright = NULL;
        
        while (p)
        {
            TreeNode *left = p->left;
            p->left = parentright;
            parentright = p->right;
            p->right = parent;
            parent = p;
            p = left;
        }
        
        return parent;
       
    }
    
    
    /* 2015-07-16, update */
    /* http://www.fgdsb.com/2015/01/04/binary-tree-upside-down/ */
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root->left) return root;
        
        TreeNode *ret = upsideDownBinaryTree(root->left);
        
        root->left->left = root->right;
        root->left->right = root;
        
        root->left = NULL;
        root->right = NULL;
        
        return ret;
    }

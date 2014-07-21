/*
    bluepp  
    2014-06-19
    2014-07-21
    May the force be with me!
    
   
 Problem:    Recover Binary Search Tree
 Source:     https://oj.leetcode.com/problems/recover-binary-search-tree/
 Notes:
 Two elements of a binary search tree (BST) are swapped by mistake.
 Recover the tree without changing its structure.
 Note:
 A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

 Solution: 1. recursive solution. O(n) space. get inorder list first.
           2. recursive solution. O(n) space. with only auxiliary two pointers.
           3. Morris inorder traversal. O(1) space. with only auxiliary two pointers.
*/


    void recoverTree(TreeNode *root) {
        vector<TreeNode *> inorder;
        inorderTraverse(root, inorder);
        TreeNode *first = NULL, *second = NULL;
        
        for (int i = 1; i < inorder.size(); i++)
        {
            if (inorder[i-1]->val < inorder[i]->val)
            {
                continue;
            }
            if (!first)
            {
                first = inorder[i-1];
            } 
            second = inorder[i];
        }
        
        swap(first->val, second->val);
       
    }
    
    void inorderTraverse(TreeNode *root, vector<TreeNode *> &inorder)
    {
        if (!root)
            return;
        inorderTraverse(root->left, inorder);
        inorder.push_back(root);
        inorderTraverse(root->right, inorder);
    }
    
/* -------------------------------------------------------------------------- */    


    void recoverTree(TreeNode *root) {
       TreeNode *first = NULL, *second = NULL, *prev = NULL;
       _recover(root, first, second, prev);
       swap(first->val, second->val);
    }
    
    void _recover(TreeNode *pCurr, TreeNode* &first, TreeNode* &second, TreeNode* &prev)
    {
        if (!pCurr)
            return;
        _recover(pCurr->left, first, second, prev);
        
        if (prev && prev->val > pCurr->val)
        {
            if (!first)
                first = prev;
            second = pCurr;    
        }
        prev = pCurr;
        
        _recover(pCurr->right, first, second, prev);
        
    }
    

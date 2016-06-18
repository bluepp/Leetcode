/*
bluepp
2016-06-19
May the force be with me!

https://leetcode.com/problems/largest-bst-subtree/

Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), 
where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \ 
 1   8   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.

*/

    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        
        int n = 0;
        int mini, maxi;
        
        _bstsub(root, n, mini, maxi);
        
        return n;
    }
    
    bool _bstsub(TreeNode *root, int &n, int &mini, int &maxi)
    {
        if (!root)
        {
            n = 0;
            return true;
        }
        
        int ln = 0, rn = 0;
        int l_mini = 0, r_mini = 0, l_maxi = 0, r_maxi = 0;
        
        bool left = _bstsub(root->left, ln, l_mini, l_maxi);
        bool right = _bstsub(root->right, rn, r_mini, r_maxi);
        
        if (left && right)
        {
            if ((!root->left || root->val >= l_maxi) && (!root->right || root->val <= r_mini))
            {
                n = ln+rn+1;
                
                mini = root->left ? l_mini : root->val;
                maxi = root->right ? r_maxi : root->val;
                
                return true;
            }
        }
        
        n = max(ln, rn);
        return false;
    }

/*
bluepp
2016-06-08
May the force be with me!

https://leetcode.com/problems/house-robber-iii/

The thief has found himself a new place for his thievery again.
There is only one entrance to this area, called the "root."
Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that "all houses in this place forms a binary tree". 
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.

*/

/* 2016-06-20, update */
/* https://leetcode.com/discuss/93998/simple-c-solution */

    int rob(TreeNode* root) {
        
        int l, r;
        
        return _rob(root, l, r);
    }
    
    int _rob(TreeNode *root, int &l, int &r)
    {
        if (!root)
            return 0;

        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = _rob(root->left, ll, lr);
        r = _rob(root->right, rl, rr);

        return max(root->val + ll + lr + rl + rr, l + r);
        
    }


/* 2016-07-03, update */

    int rob(TreeNode* root) {
        
        int n = 0;
        return _rob(root, n);
    }
    
    int _rob(TreeNode *root, int &n)
    {
        if (!root)
        {
            return 0;
        }
        
        if (!root->left && !root->right)
        {
            return root->val;
        }
        
        int nl = 0, nr = 0;
        int l = _rob(root->left, nl);
        int r = _rob(root->right,nr);
        
        n = l + r;
        
        return max(n, root->val + nl+nr);
        
    }

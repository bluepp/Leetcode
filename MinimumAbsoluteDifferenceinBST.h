/*
bluepp
2017-03-02
May the force be with me!

https://leetcode.com/problems/minimum-absolute-difference-in-bst/?tab=Description

Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.
*/

    int getMinimumDifference(TreeNode* root) {
        
        int mindiff = INT_MAX, val = INT_MIN;
        
        function<void (TreeNode *) > solve = [&](TreeNode * root)
        {
            if (!root) return;
            
            solve(root->left);
            
            if (val != INT_MIN) mindiff = min(mindiff, abs(root->val-val));
            val = root->val;
            
            solve(root->right);
        };
        
        solve(root);
        return mindiff;
    }




    int getMinimumDifference(TreeNode* root) {
        
        int mindiff = INT_MAX, val = -1;
        
        _diff(root, val, mindiff);
        return mindiff;
    }
    
    void _diff(TreeNode* root, int &val, int &mindiff)
    {
        if (root->left) _diff(root->left, val, mindiff);
        
        if (val >= 0)
        {
            mindiff = min(mindiff, abs(root->val-val));
        }
        
        val = root->val;
        if (root->right) _diff(root->right, val, mindiff);
    }

/*
    bluepp
    
    2014-06-01
    2014-07-08
    2014-08-06
    2014-09-14
    
    May the force be with me!
    
    Problem:    Binary Tree Maximum Path Sum
    Source:     https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
    Notes:
    Given a binary tree, find the maximum path sum.
    The path may start and end at any node in the tree.
    For example:
    Given the below binary tree,
        1
       / \
      2   3
    Return 6.

    Solution: Recursion...
*/


/* my version, 2014-09-14 */
    int maxPathSum(TreeNode *root) {
        int sum = INT_MIN;
        int curr_sum = 0;
        
        _path(root, sum, curr_sum);
        
        return sum;
    }
    
    void _path(TreeNode *root, int &sum, int &curr_sum)
    {
        if (!root)
        {
            curr_sum = 0;
            return;
        }
        
        int lsum = 0, rsum = 0;
        _path(root->left, sum, lsum);
        _path(root->right, sum, rsum);
        
        curr_sum = max(root->val, max(lsum, rsum)+root->val);
        sum = max(sum, max(curr_sum, root->val+lsum+rsum));
    }


--------------------------------------------------------------
   int maxPathSum(TreeNode *root) {
        int maxsum = INT_MIN;
        
        maxpath(root, maxsum);
        return maxsum;
    }
    
    int maxpath(TreeNode *root, int &maxsum)
    {
        if (!root) return 0;
        
        int l = maxpath(root->left, maxsum);
        int r = maxpath(root->right, maxsum);
        
        int sum = max(root->val, max(l,r) + root->val);
        maxsum = max(maxsum, max(l+r+root->val, sum));
        
        return sum;
        
    }    
    
    

/*
    bluepp
    2014-06-18
    May the force be with me!
    
    Problem:    Path Sum 2
    Source:     https://oj.leetcode.com/problems/path-sum-ii/
    Notes:
    Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

    For example:
    Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
    return
    [
        [5,4,11,2],
        [5,8,4,5]
    ]
 
    Solution: DFS. 
 */
 
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> vec;
        vector<vector<int> > res;
        
        _path(root, sum, vec, res);
        return res;
    }
    
    void _path(TreeNode *root, int sum, vector<int>& vec, vector<vector<int> >&res)
    {
        if (!root)
            return;
        
        if (!root->left && !root->right)
        {
            if (root->val == sum)
            {
                vec.push_back(root->val);
                res.push_back(vec);
                vec.pop_back();
                
            }
            
            return;
        }
        
        
        vec.push_back(root->val);
        _path(root->left, sum - root->val, vec, res);
        _path(root->right, sum - root->val, vec, res);
        vec.pop_back();
    }

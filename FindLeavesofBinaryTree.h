/*
2016-07-02
bluepp
May the force be with me!

https://leetcode.com/problems/find-leaves-of-binary-tree/

Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Example:
Given binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Returns [4, 5, 3], [2], [1].

Explanation:
1. Removing the leaves [4, 5, 3] would result in this tree:

          1
         / 
        2          
2. Now removing the leaf [2] would result in this tree:

          1          
3. Now removing the leaf [1] would result in the empty tree:

          []         
Returns [4, 5, 3], [2], [1].
*/

    vector<vector<int>> findLeaves(TreeNode* root) {
        
        vector<vector<int>> res;
        
        _dfs(root, res);
        return res;
    }
    
    int _dfs(TreeNode *root, vector<vector<int>> &res)
    {
        if (!root)
        {
            return -1;
        }
        
        int l = _dfs(root->left, res);
        int r = _dfs(root->right, res);
        
        int depth = max(l, r) + 1;
        
        if (depth >= res.size())
        {
            res.resize(depth+1);
        }
        
        res[depth].push_back(root->val);
        return depth;
    }

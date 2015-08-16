/*
  2015-08-16
  bluepp
  May the force be with me!
  
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

https://leetcode.com/problems/binary-tree-paths/
*/

    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        vector<string> res;
        if (!root) return res;
        
        _path(root, s, res);
        return res;
    }
    
    void _path(TreeNode *root, string s, vector<string> &res)
    {
        s += to_string(root->val);
        
        if (!root->left && !root->right)
        {
            res.push_back(s);
            return;
        }
        
        s += "->";
        if (root->left) _path(root->left, s, res);
        if (root->right) _path(root->right, s, res);
        
        int t = s.find("-");
        s.erase(s.begin()+t, s.end());
    }

/*
  2015-08-31
  bluepp
  May the force be with me!
  
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
https://leetcode.com/problems/closest-binary-search-tree-value-ii/
*/


/* 2017-01-13, update */

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        
        vector<int> res;
        priority_queue<pair<double,int>> q;
        
        _inorder(root, target, k, q);
        
        while (!q.empty())
        {
            auto it = q.top();
            q.pop();
            
            res.push_back(it.second);
        }
        
        return res;
    }
    
    
    void _inorder(TreeNode *root, double target, int k, priority_queue<pair<double, int>> &q)
    {
        if (!root) return;
        
        _inorder(root->left, target, k, q);
        
        q.push({fabs(target-root->val), root->val});
        if (q.size() > k) q.pop(); // max heap, pop the first, largest one
        
        _inorder(root->right, target, k, q);
    }

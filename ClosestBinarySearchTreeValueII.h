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

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> vec;
        if (!root) return vec;
        
        priority_queue<pair<double, int>> q;
        _cloest(root, q, target, k);
        
        while (!q.empty())
        {
            vec.push_back(q.top().second);
            q.pop();
        }
        
        return vec;
    }
    
    void _cloest(TreeNode *root, priority_queue<pair<double, int> > &q, double target, int k)
    {
        if (!root) return;
        double curr = (double)(root->val);
        q.push(make_pair(fabs(curr-target), root->val));
        if (q.size() > k) q.pop();
        
        _cloest(root->left, q, target, k);
        _cloest(root->right, q, target, k);
    }


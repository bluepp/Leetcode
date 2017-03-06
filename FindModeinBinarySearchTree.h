/*
bluepp
2017-03-06
May the force be with me!

https://leetcode.com/problems/find-mode-in-binary-search-tree/?tab=Description

Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space?
(Assume that the implicit stack space incurred due to recursion does not count).
*/


    vector<int> findMode(TreeNode* root) {
        
        vector<int> res;
        int mx = 0, cnt = 1;
        
        TreeNode *pre = NULL;
        _inorder(root, pre, cnt, mx, res);
        return res;
    }
    
    void _inorder(TreeNode* node, TreeNode*& pre, int& cnt, int& mx, vector<int>& res) {
        
        if (!node) return;
        _inorder(node->left, pre, cnt, mx, res);
        
        if (pre) {
            cnt = (node->val == pre->val) ? cnt + 1 : 1;
        }
        
        if (cnt >= mx) {
            if (cnt > mx) res.clear();
            res.push_back(node->val);
            mx = cnt;
        }
        
        if (!pre) pre = new TreeNode(node->val);
        else pre->val = node->val;
        
        _inorder(node->right, pre, cnt, mx, res);
    }

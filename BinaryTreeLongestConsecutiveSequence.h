/*
bluepp
2016-06-20
May the force be with me!

https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/

Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.

*/

    int longestConsecutive(TreeNode* root) {
        
        return _search(root, NULL, 0);
    }
    
    int _search(TreeNode *root, TreeNode*parent, int len)
    {
        if (!root) return len;
        
        len = (parent  && root->val == parent->val+1) ? len+1 : 1;
        
        int l = _search(root->left, root, len);
        int r = _search(root->right, root, len);
        
        return max(len, max(l, r));
    }

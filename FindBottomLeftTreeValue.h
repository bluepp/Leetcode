/*
bluepp
2017-02-21
May the force be with me!

https://leetcode.com/problems/find-bottom-left-tree-value/?tab=Description

iven a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.

*/

/* 1. queue, level order */
    int findBottomLeftValue(TreeNode* root) {
        
        int ret = 0;
        if (!root) return -1;
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> vec;
        
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            
            if (t)
            {
                vec.push_back(t->val);
                
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            else
            {
                if (q.empty()) break;
                
                q.push(NULL);
                vec.clear();
            }
        }
        
        ret = vec.front();
        return ret;
    }

/*
bluepp
2017-02-21
May the force be with me!

https://leetcode.com/problems/find-largest-value-in-each-tree-row/?tab=Description

You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]

*/

/* 1. level order */

    vector<int> largestValues(TreeNode* root) {
        
        vector<int> res;
        if (!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        int mx = INT_MIN;
        
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            
            if (t)
            {
                mx = max(mx, t->val);
                
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            else
            {
                res.push_back(mx);
                if (q.empty()) break;
                
                q.push(NULL);
                mx = INT_MIN;
            }
        }
        
        return res;
    }

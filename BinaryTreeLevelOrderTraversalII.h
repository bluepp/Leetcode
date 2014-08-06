/*
 -    bluepp
 -    2014-06-01
      2014-07-07
      2014-08-06
 -    May the force be with me!
 -    
 -    Problem:    Binary Tree Level Order Traversal II
 -    Source:     https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
 -    Notes:
 -    Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
 -    (ie, from left to right, level by level from leaf to root).
 -
 -    For example:
 -    Given binary tree {3,9,20,#,#,15,7},
 -        3
 -       / \
 -      9  20
 -     /  \
 -    15   7
 -    return its bottom-up level order traversal as:
 -    [
 -        [15,7]
 -        [9,20],
 -        [3],
 -    ]
 - 
 -    Solution: Queue version. On the basis of 'Binary Tree Level Order Traversal', reverse the final vector.
 - */
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        if (!root) return res;
        
        vector<int> vec;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        while (!q.empty())
        {
            TreeNode *pCurr = q.front();
            q.pop();
            
            if (pCurr)
            {
                vec.push_back(pCurr->val);
                if (pCurr->left) q.push(pCurr->left);
                if (pCurr->right) q.push(pCurr->right);
            }
            else
            {
               res.push_back(vec);
               vec.clear();
               if (q.empty()) break;
               q.push(NULL);
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }

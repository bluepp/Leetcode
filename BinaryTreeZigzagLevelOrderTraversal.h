/*
    bluepp
    
    2014-06-3
    2014-07-08
    2014-08-07
    2014-09-21
    2014-10-22
    
    May the force be with me!
    
    Problem:    Binary Tree Zigzag Level Order Traversal
    Source:     https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
    Notes:
    Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left 
    to right, then right to left for the next level and alternate between).
    For example:
    Given binary tree {3,9,20,#,#,15,7},
         3
        / \
       9  20
      / \
     15  7
    return its zigzag level order traversal as:
        [
            [3],
            [20,9],
            [15,7]
        ]

    Solution: 1. Queue + reverse.
              2. Two stacks.
              3. Vector. Contributed by yinlinglin.
              
*/

/* 2014-09-21, my version */
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        vector<int> vec;
        
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        bool left2right = true;
        
        while (!q.empty())
        {
            TreeNode *pCurr = q.front(); q.pop();
            
            if (pCurr)
            {
                vec.push_back(pCurr->val);
                
                if (pCurr->left) q.push(pCurr->left);
                if (pCurr->right) q.push(pCurr->right);
                
            }
            else
            {
                if (!left2right) reverse(vec.begin(), vec.end());
                res.push_back(vec);
                vec.clear();
                
                if (q.empty()) break;
                q.push(NULL);
                
                left2right = !left2right;
            }
        }
        
        return res;
    }




/* My version, first solution *./
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> >res;
        if (!root) return res;
        vector<int> level;
        queue<TreeNode *> q1, q2;
        q1.push(root);
        bool left2right = true;
        
        while (!q1.empty())
        {
            TreeNode *pCurr = q1.front();
            q1.pop();
            level.push_back(pCurr->val);
            
            if (pCurr->left) q2.push(pCurr->left);
            if (pCurr->right) q2.push(pCurr->right);
            
            if (q1.empty())
            {
                if (!left2right) reverse(level.begin(), level.end());
                res.push_back(level);
                level.clear();
                left2right = !left2right;
                swap(q1, q2);
            }
        }
        
        return res;
        
    }

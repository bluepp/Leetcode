/*
    bluepp
    2014-06-01
    2014-07-07
    2014-08-06
    May the force be with me!
    
     
    Problem:    Binary Tree Level Order Traversal
 
    Source:     http://leetcode.com/onlinejudge#question_102
    Notes:
    Given a binary tree, return the level order traversal of its nodes' values. 
    (ie, from left to right, level by level).

    For example:
    Given binary tree {3,9,20,#,#,15,7},
        3
       / \
      9  20
    /  \
   15   7
    return its level order traversal as:
    [
        [3],
        [9,20],
        [15,7]
    ]
 
    Solution: 1. Use queue. In order to seperate the levels, use 'NULL' as the end indicator of one level.
              2. DFS.
              
*/

/* TLE, my version */
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<int> vec;
        vector<vector<int> > res;
        queue<TreeNode *> q1, q2;
        if (!root) return res;
        q1.push(root);
        
        while (!q1.empty())
        {
            
            TreeNode *pCurr = q1.front();
            q1.pop();
            vec.push_back(pCurr->val);
            
            if (pCurr->right) q2.push(pCurr->right);
            if (pCurr->left) q2.push(pCurr->left);
            
            if (q1.empty())
            {
                res.push_back(vec);
                swap(q1, q2);
            }
        }
        
        return res;
        
    }


vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        
        vector<int> level;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        while (!q.empty())
        {
            TreeNode *pCurr = q.front();
            q.pop();
            
            if (!pCurr)
            {
                res.push_back(level);
                level.clear();
                if (q.empty()) //if not add this, time exceed
                    break;
                q.push(NULL);
            }
            else
            {
                level.push_back(pCurr->val);
                if (pCurr->left)
                    q.push(pCurr->left);
                if (pCurr->right)
                    q.push(pCurr->right);
            }
            
                
        }
        
        return res;
     
    }


/*DFS, 2014-07-07 */
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        
        _level(root, 0, res);
        return res;
    }
    
    void _level(TreeNode *root, int level, vector<vector<int> >&res)
    {
        if (!root) return;
        if (res.size() <= level) res.push_back(vector<int>());
        res[level].push_back(root->val);
        
        _level(root->left, level+1, res);
        _level(root->right, level+1, res);
    }

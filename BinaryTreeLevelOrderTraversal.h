/*
    bluepp
    
    2014-06-01
    2014-07-07
    2014-08-06
    2014-08-26
    2014-09-20
    
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


/* 2014-09-20, my version */
    vector<vector<int> > levelOrder(TreeNode *root) {
        
        vector<int> vec;
        vector<vector<int> > res;
        if (!root) return res;
        
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
        
        return res;
    }


/* my version */
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (!root) return res;
        vector<int> vec;
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        while (!q.empty())
        {
            TreeNode *tmp = q.front(); q.pop();
            if(!tmp)
            {
                res.push_back(vec);
                vec.clear();
                if (q.empty()) break;
                
                q.push(NULL);
                continue;
            }
            
            vec.push_back(tmp->val);
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
           
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

/*
    bluepp
    
    2014-06-03
    2014-07-08
    2014-08-07
    2014-09-03
    2014-09-15
    2014-09-17
    
    May the force be with me!
    
    Problem:    Binary Tree Preorder Traversal
    Source:     http://oj.leetcode.com/problems/binary-tree-preorder-traversal/
    Notes:
    Given a binary tree, return the preorder traversal of its nodes' values.   
    For example:
    Given binary tree {1,#,2,3},
        1
         \
          2
         /
        3
    return [1,2,3].
    Note: Recursive solution is trivial, could you do it iteratively?

    Solution: 1. Iterative way (stack).   Time: O(n), Space: O(n).
              2. Recursive solution.      Time: O(n), Space: O(n).
              3. Threaded tree (Morris).  Time: O(n), Space: O(1).
 */
 
 
 
 /* 2014-09-18 , my version */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> s;
        s.push(root);
        
        while (!s.empty())
        {
            TreeNode *pCurr = s.top();
            s.pop();
            
            if (pCurr)
            {
                res.push_back(pCurr->val);
                
                s.push(pCurr->right);
                s.push(pCurr->left);
            }
        }
        
        return res;
        
    }
 
 
 /* Morris Tree */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *pCurr = root;
        
        while(pCurr)
        {
            if (pCurr->left)
            {
                TreeNode *prev = pCurr->left;
                while (prev->right && prev->right != pCurr)
                {
                    prev = prev->right;
                }
                
                if (prev->right == pCurr)
                {
                    pCurr = pCurr->right;
                    prev->right = NULL;
                }
                else
                {
                    res.push_back(pCurr->val);
                    prev->right = pCurr;
                    pCurr = pCurr->left;
                }
                
            }
            else
            {
                res.push_back(pCurr->val);
                pCurr = pCurr->right;
            }
        }
        
        return res;
    }
    
 
 /* another version */
     vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        stack<TreeNode *> stk;
        TreeNode *pCurr = root;
        
        while (pCurr || !stk.empty())
        {
            if (pCurr)
            {
                res.push_back(pCurr->val);
                stk.push(pCurr);
                pCurr = pCurr->left;
            }
            else if (!stk.empty())
            {
                pCurr = stk.top()->right;
                stk.pop();
            }
        }
        
        return res;
    }
 
 
 
 
 /* 2014-09-15, my version */
     vector<int> preorderTraversal(TreeNode *root) {
        vector<int> vec;
        stack<TreeNode *> s;
        s.push(root);
        
        while (!s.empty())
        {
            TreeNode *pCurr = s.top(); s.pop();
            
            if (pCurr)
            {
                vec.push_back(pCurr->val);
            
                if (pCurr->right) s.push(pCurr->right);
                if (pCurr->left) s.push(pCurr->left);
            }
        }
        
        return vec;
       
    }
 
 
 
 
 
 /* my version, 2014-09-03 */
     vector<int> preorderTraversal(TreeNode *root) {
        vector<int> vec;
        stack<TreeNode* > s;
        TreeNode *pCurr = root;
        
        while (pCurr || !s.empty())
        {
            if (pCurr)
            {
                vec.push_back(pCurr->val);
                s.push(pCurr->right);
                s.push(pCurr->left);
            }
            
            pCurr = s.top();
            s.pop();
        }
        
        return vec;
    }
 
 
 /* first iterative version, with stack */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *pCurr = root;
        
        while (!s.empty() || pCurr)
        {
            if (pCurr)
            {
                res.push_back(pCurr->val);
                s.push(pCurr);
                pCurr = pCurr->left;
            }
            else
            {
                TreeNode *pTmp = s.top();
                s.pop();
                pCurr = pTmp->right;
            }
        }
        
        return res;
    }

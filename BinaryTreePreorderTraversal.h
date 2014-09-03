/*
    bluepp
    
    2014-06-03
    2014-07-08
    2014-08-07
    2014-09-03
    
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

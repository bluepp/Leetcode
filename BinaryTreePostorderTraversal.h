/*
    bluepp  
    2014-06-02
    2014-07-08
    May the force be with me!
    
    Problem:    Binary Tree Postorder Traversal 
    Source:     http://oj.leetcode.com/problems/binary-tree-postorder-traversal/
    Notes:
    Given a binary tree, return the postorder traversal of its nodes' values.

    For example:
    Given binary tree {1,#,2,3},
        1
         \
          2
         /
       3
    return [3,2,1].

    Note: Recursive solution is trivial, could you do it iteratively?

    Solution: 1. Iterative way (stack).   Time: O(n), Space: O(n).
              2. Recursive solution.      Time: O(n), Space: O(n).
              3. Threaded tree (Morris).  Time: O(n), Space: O(1). 
              for more detailed explanations: 
              http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
*/

/* my version */
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        
        stack<TreeNode*> s;
        TreeNode *prev = NULL;
        s.push(root);
        
        while(!s.empty())
        {
            TreeNode *pCurr = s.top();
            
            if (prev || prev->left == pCurr || prev->right == pCurr)
            {
                if (pCurr->left)
                    s.push(pCurr->left);
                else if (pCurr->right)
                    s.push(pCurr->right);
            }
            else if(prev == pCurr->left)
            {
                if (pCurr->right)
                    s.push(pCurr->right);
            }
            else 
            {
                res.push_back(pCurr->val);
                s.pop();
            }
        }
        
        return res;
      
    }
    
    
    -----------------------------
    
    vector<int> postorderTraversal(TreeNode *root) {
      vector<int> res;
      
      TreeNode *prev = NULL, *pCurr = root;
      stack<TreeNode*> s;
      
      
      while (s.empty() || pCurr)
      {
          if (pCurr)
          {
              s.push(pCurr);
              pCurr = pCurr->left;
          }
          else
          {
              TreeNode *ptmp = s.top();
              if (pCurr->right && prev != pCurr->right)
              {
                pCurr = ptmp->right;
              }
              else
              {
                  res.push_back(pCurr->val);
                  s.pop();
                  prev = pCurr;
              }
            
          }
       }
       
       return res;
      
      
    }

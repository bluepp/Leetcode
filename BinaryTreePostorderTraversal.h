/*
    bluepp  
    
    2014-06-02
    2014-07-08
    2014-08-07
    2014-11-23
    
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
        if (!root) return res;
        stack<TreeNode*> s;
        TreeNode *prev = NULL;
        s.push(root);
        
        while (!s.empty())
        {
            TreeNode *pCurr = s.top();
            if (!prev || prev->left == pCurr|| prev->right == pCurr)
            {
                if (pCurr->left) s.push(pCurr->left);
                else if(pCurr->right) s.push(pCurr->right);
            }
            else if (pCurr->left == prev)
            {
                if (pCurr->right) s.push(pCurr->right);
            }
            else
            {
                res.push_back(pCurr->val);
                s.pop();
            }
            
            prev = pCurr;
        }
        
        return res;
    }
    
    /* ---------------------------------- */
    /* Morris , 2015-07-24 */
        vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode dump(0);
        dump.left = root;
        TreeNode *cur = &dump, *prev = NULL;
        while (cur)
        {
            if (cur->left)
            {
                prev = cur->left;
                while (prev->right != NULL && prev->right != cur)
                    prev = prev->right;

                if (prev->right == NULL)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    printReverse(cur->left, prev, res);  // call print
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
            else
            {
                cur = cur->right;
            }
        }
        
        return res;
    }
        
    void printReverse(TreeNode* from, TreeNode *to, vector<int>& res) // print the reversed tree nodes 'from' -> 'to'.
    {
        reverse(from, to);
        
        TreeNode *p = to;
        while (true)
        {
            res.push_back(p->val);
            if (p == from)
                break;
            p = p->right;
        }
        
        reverse(to, from);
    }
    
        
    void reverse(TreeNode *from, TreeNode *to) // reverse the tree nodes 'from' -> 'to'.
    {
        if (from == to)
            return;
        TreeNode *x = from, *y = from->right, *z;
        while (true)
        {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
            if (x == to)
                break;
        }
    }
    
    /* ----------------------------- */
    
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *pCurr = root, *prev = NULL;
        
        while (pCurr || !s.empty())
        {
            if (pCurr)
            {
                s.push(pCurr);
                pCurr = pCurr->left;
            }
            else
            {
                TreeNode *pTmp = s.top();
                
                if (pTmp->right && prev != pTmp->right)
                {
                    pCurr = pTmp->right;
                }
                else
                {
                    res.push_back(pTmp->val);
                    s.pop();
                    prev = pTmp;
                }
            }
        }
        
        return res;
    }

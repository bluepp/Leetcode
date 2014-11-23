/*
    bluepp
    
    2014-06-27
    2014-08-02
    2014-08-19
    2014-08-27
    2014-09-07, iterative solution
    2014-11-23
    
    May the force be with me!
    
    
 Problem:    Sum Root to Leaf Numbers
 Source:     https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
 Notes:
 Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 An example is the root-to-leaf path 1->2->3 which represents the number 123.
 Find the total sum of all root-to-leaf numbers.
 For example,
   1
  / \
 2   3
 The root-to-leaf path 1->2 represents the number 12.
 The root-to-leaf path 1->3 represents the number 13.
 Return the sum = 12 + 13 = 25.

 Solution: 1. Recursion (add to sum when reaching the leaf).
           2. Iterative solution.
 */
 
 
 /* recursion, my version */
    int sumNumbers(TreeNode *root) {
        return _sum(root, 0);
    }
    
    int _sum(TreeNode *root, int n)
    {
        if (!root) return 0;
        int value = n*10 + root->val;
        if (!root->left && !root->right) return value;
        
        int l = _sum(root->left, value);
        int r = _sum(root->right, value);
        
        return l+r;
    }
    
    /* iteration  */
    
    int sumNumbers(TreeNode *root) {
        if (!root) return 0;
        
        int res = 0;
        queue<pair<TreeNode *, int> > q;
        q.push(make_pair(root, 0));
        
        while (!q.empty())
        {
            TreeNode *pNode = q.front().first;
            int sum = q.front().second*10 + pNode->val;
            q.pop();
            
            if (!pNode->left && !pNode->right)
            {
                res += sum;
                continue;
            }
            
            if (pNode->left) q.push(make_pair(pNode->left, sum));
            if (pNode->right) q.push(make_pair(pNode->right, sum));
            
            
        }
        
        return res;
      
    }

/*
    bluepp
    2014-06-30
    2014-07-31
    2014-08-17
    2014-08-28
    May the force be with me!
    

 Problem:    Unique Binary Search Trees II
 Source:     hhttps://oj.leetcode.com/problems/unique-binary-search-trees-ii/
 Notes:
 Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 For example,
 Given n = 3, your program should return all 5 unique BST's shown below.
 1         3     3      2      1
  \       /     /      / \      \
   3     2     1      1   3      2
  /     /       \                 \
 2     1         2                 3

 Solution: 1. DFS directly. (from the Internet)
           2. DP + DFS. (???????)
              a. Generate trees for 'n' from 1 to n. (DP)
              b. When generate trees for n = i, get the left and right subtrees 
                 by copying tree structures of dp[1...i-1]. (copy tree uses DFS)
*/


/* DFS */
 vector<TreeNode *> generateTrees(int n) {
       return _gen(1, n);
    }
    
    vector<TreeNode *> _gen(int l, int r)
    {
        vector<TreeNode *> res;
        if (l > r)
        {
            res.push_back(NULL);
            return res;
        }
        
        for (int k = l; k <= r; k++)
        {
            vector<TreeNode *> left = _gen(l, k-1);
            vector<TreeNode *> right = _gen(k+1, r);
            
            for (int i = 0; i < left.size(); i++)
            {
                for (int j = 0; j < right.size(); j++)
                {
                    TreeNode *root = new TreeNode(k);
                    root->left = left[i];
                    root->right = right[j];
                    res.push_back(root);
                }
            }
            
           
        }
    
    }

/*
Bluepp
2016-06-18
May the force be with me!

https://leetcode.com/problems/binary-tree-vertical-order-traversal/

Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:

Given binary tree [3,9,20,null,null,15,7],
   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,8,4,0,1,7],
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2
return its vertical order traversal as:
[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]
Show Company Tags
Show Tags
Show Similar Problems

*/

    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if (!root) return res;
        
        map<int, vector<int>> hm;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty())
        {
            TreeNode *pNode = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            hm[col].push_back(pNode->val);
            
            if (pNode->left) q.push({pNode->left, col-1});
            if (pNode->right) q.push({pNode->right, col+1});
        }
        
        for (auto p : hm)
        {
            res.push_back(p.second);
        }
        
        return res;
    }

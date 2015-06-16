/*
  2015-06-17
  bluepp
  May the force be with me!
  
Binary Tree Right Side View Total Accepted: 11375 Total Submissions: 42189 My Submissions Question Solution 
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

https://leetcode.com/problems/binary-tree-right-side-view/
*/

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        TreeNode *prev = NULL;
        while (!q.empty())
        {
            TreeNode *pCurr = q.front();
            q.pop();
            
            if (pCurr)
            {
                if (pCurr->left) q.push(pCurr->left);
                if (pCurr->right) q.push(pCurr->right);
                
                prev = pCurr;
            }
            else
            {
                if (prev) res.push_back(prev->val);
                
                if (q.empty()) break;
                q.push(NULL);
            }
        }
    
        return res;
    }

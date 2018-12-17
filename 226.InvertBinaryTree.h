/*
  2015-06-13
  bluepp
  May the force be with me!

  Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

https://leetcode.com/problems/invert-binary-tree/
*/

/* recursion, 2015-07-20 update */
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        
        TreeNode *L = root->left, *R = root->right;
        root->left = invertTree(R);
        root->right = invertTree(L);
        
        return root;
    }
    
/* queue */
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        while (!q.empty())
        {
            TreeNode *pCurr = q.front();
            q.pop();
            
            if (pCurr)
            {
                TreeNode *pLeft = pCurr->left;
                pCurr->left = pCurr->right;
                pCurr->right = pLeft;
                
                if (pCurr->left) q.push(pCurr->left);
                if (pCurr->right) q.push(pCurr->right);
            }
            else
            {
                if (q.empty()) break;
                q.push(NULL);
            }
        }
        
        return root;
        
    }

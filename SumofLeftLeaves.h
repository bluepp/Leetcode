/*
2016-09-29
bluepp
May the force be with me!

https://leetcode.com/problems/sum-of-left-leaves/

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/

/* 2016-10-13, another one */
    int sumOfLeftLeaves(TreeNode* root) {
        
        if (!root) return 0;
        if (root->left && !root->left->left && !root->left->right)
        {
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
 
    }



    int sumOfLeftLeaves(TreeNode* root) {
        
        int ret = 0;
        if (!root)
        {
            return 0;
        }
        
        queue<TreeNode *> q;
        q.push(root);
        
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            
            if (t->left)
            {
                q.push(t->left);
                
                if (!t->left->left && !t->left->right)
                {
                    ret += t->left->val;
                }
            }
            
            if (t->right)
            {
                q.push(t->right);
            }
        }
        
        return ret;
    }

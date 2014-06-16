/*
    bluepp
    2014-06-16
    May the force be with me!

    Problem:    Minimum Depth of Binary Tree
    Source:     https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
    Notes:
    Given a binary tree, find its minimum depth.
    The minimum depth is the number of nodes along the shortest path from the root node 
    down to the nearest leaf node.
 
    Solution: 1. Recursion. Pay attention to cases when the non-leaf node has only one child.
              2. Iteration + Queue. Contributed by SUN Mian(孙冕).
 */
 
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        else if (!root->left)
            return minDepth(root->right)+1;
        else if (!root->right)
            return minDepth(root->left)+1;
        else
            return min(minDepth(root->left),minDepth(root->right))+1;
    }
    
    
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int depth = 1;
        
        while (true)
        {
            TreeNode *pCurr = q.front();
            q.pop();
            
            if (!pCurr)
            {
                depth++;
                q.push(NULL);
            }
            else
            {
                if (!pCurr->left && !pCurr->right)
                    break;
                if (pCurr->left)
                    q.push(pCurr->left);
                if (pCurr->right)
                    q.push(pCurr->right);
            }
        }
        
        return depth;
       
    }

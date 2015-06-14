/*
  2015-06-14
  bluepp
  May the force be with me!
  
  Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, a
nd all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.

https://leetcode.com/problems/count-complete-tree-nodes/
*/

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int h_l = 0, h_r = 0;
        TreeNode *p = root;
        while (p)
        {
            h_l++;
            p = p->left;
        }
        
        p = root;
        while (p)
        {
            h_r++;
            p = p->right;
        }
        
        if (h_l == h_r) return pow(2, h_l)-1;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }

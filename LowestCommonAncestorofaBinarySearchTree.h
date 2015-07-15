/*
  bluepp
  2015-07-15
  May the force be with me!
  
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes v and w as the lowest node in 
T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. 
Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
*/

/* recursion */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (!root || !p || !q) return NULL;
        if (max(p->val, q->val) < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (min(p->val, q->val) > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
            return root;
    }
    
/* botton up, o(n) */
/* http://articles.leetcode.com/2011/07/lowest-common-ancestor-of-a-binary-tree-part-i.html */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        
        if (root == p ||root == q) return root;
        TreeNode *L = lowestCommonAncestor(root->left, p, q);
        TreeNode *R = lowestCommonAncestor(root->right, p, q);
        
        if (L && R) return root;
        return L ? L : R;
    }
  

/*
    bluepp
    2014-06-09
    2014-07-10
    2014-08-13
    May the force be with me!
    
    
    Problem:    Flatten Binary Tree to Linked List
    Source:     https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
    Notes:
    Given a binary tree, flatten it to a linked list in-place.
    For example,
    Given
         1
        / \
       2   5
      / \   \
     3   4   6
    The flattened tree should look like:
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6
    Hints:
    If you notice carefully in the flattened tree, each node's right child points to the next node 
    of a pre-order traversal.

    Solution: Recursion. Return the last element of the flattened sub-tree.
*/

/* my version*/

   void flatten(TreeNode *root) {
        if (!root)
            return;
        TreeNode *L = root->left;
        TreeNode *R = root->right;
        
        flatten(L);
        flatten(R);
        
        root->right = L;
        root->left = NULL;
        
        while (root->right)
            root = root->right;
        root->right = R;    
        
    }
    
    
/* */
void flatten(TreeNode *root) {
        TreeNode *end = NULL;
        _flatten(root, end);
    }
    
    void _flatten(TreeNode *root, TreeNode *&end)
    {
        if (!root)
            return;
        TreeNode *lend = NULL, *rend = NULL;
        _flatten(root->left, lend);
        _flatten(root->right, rend);
        
        if (root->left)
        {
            lend->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        
        end = rend? rend : (lend ? lend : root);
    }

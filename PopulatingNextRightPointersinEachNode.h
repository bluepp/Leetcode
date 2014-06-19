/*
    bluepp
    2014-06-19
    May the force be with me!
    
    Problem:    Populating Next Right Pointers in Each Node
    Source:     https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
    Notes:
    Given a binary tree
    struct TreeLinkNode {
        TreeLinkNode *left;
        TreeLinkNode *right;
        TreeLinkNode *next;
    }
    Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
    Initially, all next pointers are set to NULL.
    Note:
    You may only use constant extra space.
    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
    For example,
    Given the following perfect binary tree,
      1
    /  \
   2    3
  / \  / \
 4  5  6  7
    After calling your function, the tree should look like:
      1 -> NULL
    /  \
   2 -> 3 -> NULL
  / \  / \
 4->5->6->7 -> NULL

    Solution: 1. Iterative: Two 'while' loops: root->leaf and left->right.
              2. Iterative: Queue. Use extra space.
              3. Recursive: DFS. Defect: Use extra stack space for recursion.
 */
 
 
    void connect(TreeLinkNode *root) {
        if (!root)
        {
            return;
        }
        
        if (root->left)
        {
            root->left->next = root->right?root->right: NULL;
        }
        if (root->right)
        {
            root->right->next = root->next? root->next->left : NULL;
        }
        
        connect(root->left);
        connect(root->right);
        
    }
 
 
 
 

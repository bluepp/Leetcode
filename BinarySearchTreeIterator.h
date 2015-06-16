/*
  bluepp
  2015-01-02
  May the force be with me!
  
  https://oj.leetcode.com/problems/binary-search-tree-iterator/
  Binary Search Tree Iterator Total Accepted: 1173 Total Submissions: 3951 My Submissions Question Solution 
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/

/*
  1. inorder traversal
  2. morriors tree
*/


/* inorder traversal, stack */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        node = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (stk.empty() && !node) return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        if (stk.empty() && !node) return 0;
        
        while (node)
        {
            stk.push(node);
            node = node->left;
        }
        
        int res = 0;
        node = stk.top();
        stk.pop();
        res = node->val;
        node = node->right;
        return res;
    }

private:
    TreeNode *node;
    stack<TreeNode *> stk;
   
};
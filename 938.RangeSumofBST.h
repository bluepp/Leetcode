/*
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.

 

Example 1:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32
Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23
 

Note:

The number of nodes in the tree is at most 10000.
The final answer is guaranteed to be less than 2^31.
*/

    int rangeSumBST(TreeNode* root, int L, int R) {
        
        int sum = 0;
        _bst(root, L, R, sum);
        
        return sum;
    }
    
    void _bst(TreeNode *root, int L, int R, int &sum) {
        
        if (!root) {
            return;
        }
        
        if (root->val >= L && root->val <= R) {
            sum += root->val;
        }
        
        _bst(root->left, L, R, sum);
        _bst(root->right, L, R, sum);
        
    }

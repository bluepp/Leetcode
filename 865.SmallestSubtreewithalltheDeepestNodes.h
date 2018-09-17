/* 
Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.

A node is deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is that node, plus the set of all descendants of that node.

Return the node with the largest depth such that it contains all the deepest nodes in its subtree.

 

Example 1:

Input: [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation:



We return the node with value 2, colored in yellow in the diagram.
The nodes colored in blue are the deepest nodes of the tree.
The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization of the given tree.
The output "[2, 7, 4]" is a serialization of the subtree rooted at the node with value 2.
Both the input and output have TreeNode type.
*/

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode *res;
        _depth(root, res);
        
        return res;
    }
    
    int _depth(TreeNode *root, TreeNode *&res) {
        if (!root) {
            return 0;
        }
        
        TreeNode *lnode, *rnode;
        
        int l = _depth(root->left, lnode);
        int r = _depth(root->right, rnode);
        
        if (l == r) {
            res = root;
        } else {
            res = (l > r) ? lnode : rnode;
        }
        
        return max(l, r) + 1;
    } 

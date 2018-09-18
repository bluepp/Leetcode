/*
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
*/

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> v1, v2;
        
        _getleaf(root1, v1);
        _getleaf(root2, v2);
        
        return v1 == v2;
    }
   
    void _getleaf(TreeNode*root, vector<int> &vec) {
        
        if (!root){
            return;
        }
        
        if (!root->left && !root->right) {
            vec.push_back(root->val);
            return;
        }
        
        _getleaf(root->left, vec);
        _getleaf(root->right, vec);
    }

/*
	bluepp	
	2014-06-05
	2014-07-08
	2014-08-12
	May the force be with me!
	
	Problem:    Construct Binary Tree from Inorder and Postorder Traversal
 	Source:     https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 	Notes:
 	Given inorder and postorder traversal of a tree, construct the binary tree.
 	Note:
 	You may assume that duplicates do not exist in the tree.

 	Solution: Recursion.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
  	
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        return _build(inorder.begin(), postorder.begin(), n);
    }
    
    TreeNode *_build(vector<int>::iterator inorder, vector<int>::iterator postorder, int n)
    {
        if (n == 0) return NULL;
        int rootval = postorder[n-1];
        TreeNode *root = new TreeNode(rootval);
        
        vector<int>::iterator it = find(inorder, inorder+n, rootval);
        int index = it-inorder;
        
        root->left = _build(inorder, postorder, index);
        root->right = _build(inorder+index+1, postorder+index, n-index-1);
        return root;
    }

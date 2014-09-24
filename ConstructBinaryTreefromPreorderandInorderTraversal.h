/*
	bluepp
	
	2014-06-05
	2014-07-09
	2014-08-12
	2014-09-25
	
	May the force be with me!
	
	Problem:    Construct Binary Tree from Preorder and Inorder Traversal
  	Source:     https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 	Notes:
 	Given preorder and inorder traversal of a tree, construct the binary tree.
 	Note:
 	You may assume that duplicates do not exist in the tree.

 	Solution: Recursion.
 */
 
   TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return _build(preorder.begin(), inorder.begin(), preorder.size());
    }
    
    TreeNode* _build(vector<int>::iterator preorder, vector<int>::iterator inorder, int n) 
    {
        if (n == 0) return NULL;
        int rootval = *preorder;
        
        vector<int>::iterator it = find(inorder, inorder + n, rootval);
        int index = it - inorder;
        
        TreeNode *root = new TreeNode(rootval);
        root->left = _build(preorder+1, inorder, index);
        root->right = _build(preorder+1+index, inorder+index+1, n-1-index);
        
        return root;
    }

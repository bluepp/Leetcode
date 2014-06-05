/*
	bluepp
	2014-06-06
	May the force be with me!

	Problem:    Convert Sorted Array to Binary Search Tree
	Source:     https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 	Notes:
 	Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 	Solution: Recursion.
*/

	TreeNode *sortedArrayToBST(vector<int> &num) {
        int n = num.size();
        return _build(num, 0, n-1);
        
    }
    
    TreeNode* _build(vector<int>&num, int start, int end)
    {
        if(start > end) return NULL;
        
        int m = start + (end - start) /2;
        
        TreeNode* root = new TreeNode(num[m]);
        root->left = _build(num, start, m-1);
        root->right = _build(num, m+1, end);
        
        return root;
    }

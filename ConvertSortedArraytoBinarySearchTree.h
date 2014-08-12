/*
	bluepp
	2014-06-06
	2014-07-09
	2014-08-12
	May the force be with me!

	Problem:    Convert Sorted Array to Binary Search Tree
	Source:     https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 	Notes:
 	Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 	Solution: Recursion.
*/

    TreeNode *sortedArrayToBST(vector<int> &num) {
        int n = num.size();
        return _bst(num, 0, n-1);
    }
    
    TreeNode* _bst(vector<int> &num, int l, int r)
    {
        if (l > r) return NULL;
        int m = l + (r-l)/2;
        int rootval = num[m];
        
        TreeNode *root = new TreeNode(rootval);
        root->left = _bst(num, l, m-1);
        root->right = _bst(num, m+1, r);
        
        return root;
    }

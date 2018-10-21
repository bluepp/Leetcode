/*
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
        
*/

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();       
        return _convert(nums, 0, n-1);
    }
    
    TreeNode * _convert(vector<int> &nums, int l, int r) {
        
        if (l > r) {
            return NULL;
        }
        
        int maxindex = l, maxval = nums[maxindex];
        for (int i = l; i <= r; i++) {
            if (nums[i] > maxval) {
                maxindex = i;
                maxval = nums[i];
            }
        }
        
        TreeNode *root = new TreeNode(maxval);
        root->left = _convert(nums, l, maxindex-1);
        root->right = _convert(nums, maxindex+1, r);
        
        return root;
    }
        
        

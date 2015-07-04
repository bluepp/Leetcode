/*
  2015-07-04
  bluepp
  May the froce be with me!
  
  Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
How would you optimize the kthSmallest routine?

*/

    int kthSmallest(TreeNode* root, int k) {
        int ret = 0, count = 0;
        
        function<void(TreeNode*) > solve = [&](TreeNode *node)
        {
            if (!node) return;
            
            solve(node->left);
            if (++count == k)
            {
                ret = node->val;
                return;
            }
            
            solve(node->right);
        };
        
        
        solve(root);
        return ret;
    }

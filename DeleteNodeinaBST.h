/*
bluepp
2017-01-14
May the force be with me!

https://leetcode.com/problems/delete-node-in-a-bst/

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
    
*/

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (!root) return NULL;
        
        if (root->val == key)
        {
            if (!root->right) return root->left;
            else
            {
                TreeNode *curr = root->right;
                while (curr->left)
                {
                    curr = curr->left;
                }
                
                swap(root->val, curr->val);
            }
        }
        
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        
        return root;
        
    }


/* 2017-02-07, recursion */
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (!root) return NULL;
        
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (!root->left || !root->right)
            {
                root = (root->left) ? root->left : root->right;
            }
            else
            {
                TreeNode *curr = root->right;
                
                while (curr->left) curr = curr->left;
                root->val = curr->val;
                root->right = deleteNode(root->right, curr->val);
            }
        }
        
        return root;
        
    }

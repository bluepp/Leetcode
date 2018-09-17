/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
*/

    bool findTarget(TreeNode* root, int k) {
        
        unordered_map<int, int> map;
        return _find(root, k, map);
       
    }   
    
    bool _find(TreeNode *root, int k, unordered_map<int, int> &map) {
        if (!root) {
            return false;
        }
        
        if (map.count(k-root->val)) {
            return true;
        }
        
        map[root->val]++;
        
        return _find(root->left, k, map) || _find(root->right, k, map);
    }

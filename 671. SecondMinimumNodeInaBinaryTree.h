/*
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:
Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
*/    

/* recursion */
    int findSecondMinimumValue(TreeNode* root) {
        int first = root->val, second = INT_MAX;
        
        _dfs(root, first, second);
        return (first == second || second == INT_MAX) ? -1 : second; 
    }
    
    void _dfs(TreeNode *root, int &first, int &second) {
        if (!root) {
            return;
        }
        
        _dfs(root->left, first, second);
        _dfs(root->right, first, second);
        
        if (root->val != first && second > root->val) {
            second = root->val;
        }
        
    }

/* iterative */

    int findSecondMinimumValue(TreeNode* root){
        int first = root->val, second = INT_MAX;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            
            if (t->val > first && t->val < second) {
                second = t->val;
            }
            
            if (t->left) {
                q.push(t->left);
            }
            
            if (t->right) {
                q.push(t->right);
            }
        }
        
        return (second == first || second == INT_MAX) ? -1 : second;
    }

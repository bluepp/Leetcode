/*
We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.
 

Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.
*/

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        _dfs(root, target, K, res);
        
        return res;
    }
    
    int _dfs(TreeNode *node, TreeNode *target, int k, vector<int>& res) {
        if (!node){
            return -1; 
        } else if (node == target){
            _subtree(node, 0, k, res);
            return 1;
        } else {
            int l = _dfs(node->left, target, k, res), r = _dfs(node->right, target, k, res);
            
            if (l != -1){
                if (l == k){
                    res.push_back(node->val);
                }
                
                _subtree(node->right, l+1, k, res);
                return l+1;
            } else if (r != -1){
                if (r == k){
                    res.push_back(node->val);
                }
                
                _subtree(node->left, r+1, k, res);
                return r+1;
            } else {
                return -1;
            }
        }
    }
    
    void _subtree(TreeNode *node, int dist, int k, vector<int> &res){
        if (!node){
            return;
        }
        
        if (dist == k){
            res.push_back(node->val);
        } else {
            _subtree(node->left, dist+1, k, res);
            _subtree(node->right, dist+1, k, res);
        }
    }



/* wrong , do not consider target is leave */
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        
        if (root == target) {
            _dist(root, K, res);
            return res;
        }
        
        int lstep = 1, rstep = 1;
        if (_search(root->left, target, K, lstep, res)) {
            _dist(root->right, K-1-lstep, res);
        } else if (_search(root->right, target, K, rstep, res)){
            _dist(root->left, K-1-rstep, res);
        }
        
        return res;
    }
    
    bool _search(TreeNode *root, TreeNode* target, int k, int &step, vector<int> &res) {
        
        if (!root){
            return false;
        }
                
        if (root == target) {
            _dist(root, k, res);
            return true;
        }
        
        step++;
        
        return _search(root->left, target, k, step, res) || 
            _search(root->right, target, k, step, res); 
    }
    

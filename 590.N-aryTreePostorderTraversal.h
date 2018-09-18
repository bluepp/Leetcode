/*
Given an n-ary tree, return the postorder traversal of its nodes' values.

 
For example, given a 3-ary tree:



 
Return its postorder traversal as: [5,6,3,2,4,1].
*/
    vector<int> postorder(Node* root) {
        
        vector<int> res;
        
        _post(root, res);
        return res;
    }
    
    void _post(Node* root, vector<int> &res) {
        if (!root) {
            return;
        }
       
        for(auto p : root->children) {
            _post(p, res);
        }
        
        res.push_back(root->val);
       
    }

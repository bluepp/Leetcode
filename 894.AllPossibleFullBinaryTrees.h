/*
A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.

Each node of each tree in the answer must have node.val = 0.

You may return the final list of trees in any order.

 

Example 1:

Input: 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
Explanation:

 
 */   
 
 vector<TreeNode*> allPossibleFBT(int N) {
        if (N % 2 == 0) return {};
    
        if (N == 1) return {new TreeNode(0)};
        vector<TreeNode*> ans;
    
        for (int i = 1; i < N; i += 2) {      
            for (const auto& l : allPossibleFBT(i){
                for (const auto& r : allPossibleFBT(N - i - 1)) {
                    auto root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }    
        }
    
        return ans;
    }

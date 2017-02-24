/*
bluepp
2017-01-17
May the force be with me!

https://leetcode.com/problems/serialize-and-deserialize-bst/

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in
a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another 
computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your s
erialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized 
to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

*/

/* 2017-02-24, update */

  // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        ostringstream os;
         _serialize(root, os);
         return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
     
        istringstream is(data);
        return _deserialize(is);
    }
  
    
    void _serialize(TreeNode* root, ostringstream& os) {
        if (!root) 
        {
            os << "# ";
            return;
        }
    
        os << root->val << " ";
        _serialize(root->left, os);
        _serialize(root->right, os);
    }
  
    
    
    TreeNode* _deserialize(istringstream& is) {
        string val = "";
        is >> val;
        if (val == "#") return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = _deserialize(is);
        node->right = _deserialize(is);
        return node;
    }
    

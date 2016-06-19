/*
bluepp
2016-06-09
May the force be with me!

https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

*/

/* three ways */
/* https://leetcode.com/discuss/70853/recursive-dfs-iterative-dfs-and-bfs */


class Codec {
private:
    int helper(string &data)
    {
        int pos = data.find(',');
        int val = stoi(data.substr(0, pos));
        data = data.substr(pos+1);
        
        return val;
    }

 
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if (!root) return "#";
        else return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
      
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        return _des(data);
    }
    
    TreeNode *_des(string &data)
    {
        if (data[0] == '#')
        {
            if (data.size() > 1)
            {
                data = data.substr(2);
            }
            
            return NULL;
        }
        else
        {
            TreeNode *node = new TreeNode(helper(data));
            
            node->left = _des(data);
            node->right = _des(data);
            
            return node;
        }
    }
    
    
   
};

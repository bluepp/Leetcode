/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following 3-ary tree

 



 

as [1 [3[5 6] 2 4]]. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Note:

N is in the range of [1, 1000]
Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        
        string res;
        _serialize(root, res);
        
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        
        istringstream iss(data);
        return _deserialize(iss);
    }
    
    void _serialize(Node* node, string &res){
        if (!node){
            res += "#";
        } else {
            res += to_string(node->val) + " " + to_string(node->children.size()) + " ";
            
            for (auto child : node->children){
                _serialize(child, res);
            }
        }
    }

    
    Node * _deserialize(istringstream& iss){
        
        string val, size;
        
        iss >> val;
        
        if (val == "#"){
            return NULL;
        }
        
        iss >> size;
        Node *node = new Node(stoi(val), {});
        
        for (int i = 0; i < stoi(size); i++){
            node->children.push_back(_deserialize(iss));
        }
        
        return node;
    }

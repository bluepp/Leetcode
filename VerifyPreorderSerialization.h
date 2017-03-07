/*
bluepp
2016-06-02
May the force be with me!

One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
*/

/* 2017-03-08, update */

   bool isValidSerialization(string preorder) {
        
        if (preorder.empty()) return false;
        
        istringstream in(preorder);
        vector<string> v;
        string val;
        int d = 0;
        
        while (getline(in, val, ',')) 
        {
            v.push_back(val);
        }
        
        for (int i = 0; i < v.size()-1; i++)
        {
            if (v[i] == "#")
            {
                if (d == 0) return false;
                else d--;
            }
            else d++;
        }
        
        return d ? false : v.back() == "#";
    }


/* 1 */
    bool isValidSerialization(string preorder) {
        
        if (preorder.empty()) return false;
        
        preorder += ',';
        int sz = preorder.size(), index = 0;
        int capacity = 1;
        
        for (index = 0; index < sz; index++)
        {
            if (preorder[index] != ',') continue;
            capacity--;
            
            if (capacity < 0) return false;
            if (preorder[index-1] != '#') capacity += 2;
        }
        
        return capacity == 0;
    }

/* 2 */
    bool isValidSerialization(string preorder) {
        int null = 0, node = 1;
        
        for (int i = 0; i < preorder.size(); i++)
        {
            if (preorder[i] == ',') node ++;
            if (preorder[i] == '#') null++;
            if (2 * null == node+1 && i != preorder.length()-1) return false;
        }
        
        return 2*null == node+1;
      
    }

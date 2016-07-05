/*
  2015-09-01
  bluepp
  May the force be with me!
  
  

Design an algorithm to encode a list of strings to a string.
The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.
*/

/* https://leetcode.com/discuss/54906/accepted-simple-c-solution */
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encode = "";
        for (auto p : strs)
        {
            int len = p.size();
            encode += to_string(len)+"@"+p;
        }
        
        return encode;
    }

/* 2016-07-06, update */
    vector<string> decode(string s) {
        
        vector<string> res;
        
        int i = 0;
        while (i < s.length())
        {
            int pos = s.find_first_of('@', i);
            int len = stoi(s.substr(i, pos-i));
            
            res.push_back(s.substr(pos+1, len));
            
            i = pos+len+1;
        }
        
        return res;
    }


    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> r;
        int head = 0;
        
        while (head < s.size())
        {
            int at_pos = s.find_first_of('@', head);
            int len = stoi(s.substr(head, at_pos - head));
            head = at_pos + 1;
            r.push_back(s.substr(head, len));
            head += len;
        }
        
        return r;
    }
};

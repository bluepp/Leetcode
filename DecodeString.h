/*
bluepp
2016-10-17
May the force be with me!

https://leetcode.com/problems/decode-string/

Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

*/

/* 2017-01-08, stack */
    string decodeString(string s) {
        
        string res = "", t = "";
        stack<int> s_num;
        stack<string> s_str;
        int cnt = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            
            if (s[i] >= '0' && s[i] <= '9') 
            {
                cnt = 10 * cnt + s[i] - '0';
                
            } 
            else if (s[i] == '[') 
            {
                s_num.push(cnt);
                s_str.push(t);
                cnt = 0; 
                t.clear();
                
            } 
            else if (s[i] == ']') 
            {
                int k = s_num.top(); s_num.pop();
                for (int j = 0; j < k; ++j) s_str.top() += t;
                t = s_str.top(); s_str.pop();
            } 
            else {
                t += s[i];
            }
        }
        
        return s_str.empty() ? t : s_str.top();
      
    }




    string decodeString(string s) {
        
        int i = 0;
        return _decode(s, i);
    }
    
    string _decode(string s, int &i)
    {
        string res = "";
        int n = s.size();
        while (i < n && s[i] != ']') {
            if (s[i] < '0' || s[i] > '9') {
                res += s[i++];
            } else {
                int cnt = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    cnt = cnt * 10 + s[i++] - '0';
                }
                ++i;
                string t = _decode(s, i);
                ++i;
                while (cnt-- > 0) {
                    res += t;
                }
            }
        }
        
        return res;
    }
    

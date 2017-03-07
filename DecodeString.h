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

/* 2017-03-07, stack */

    string decodeString(string s) {
        
        string res;
        stack<string> stk_s;
        stack<int> stk_n;
        int n = s.length();
        
        string t = "";
        int num = 0;
        
        for (auto p : s)
        {
            if (p >= '0' && p <= '9')
            {
                num = num*10 + p -'0';
            }
            else if (p == '[')
            {
                stk_n.push(num);
                stk_s.push(t);
                
                num = 0;
                t.clear();
            }
            else if (p == ']')
            {
                int count = stk_n.top();
                stk_n.pop();
                
                for (int i = 0; i < count; i++)
                {
                    stk_s.top() += t;
                }
                
                t = stk_s.top();
                stk_s.pop();
                
            }
            else
            {
                t += p;
            }
        }
        
        return stk_s.empty() ? t : stk_s.top();      
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
    

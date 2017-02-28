/*
bluepp
2016-06-16
May the force be with me!

https://leetcode.com/problems/rearrange-string-k-distance-apart/

Given a non-empty string str and an integer k, 
rearrange the string such that the same characters are at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:
str = "aabbcc", k = 3

Result: "abcabc"

The same letters are at least distance 3 from each other.
Example 2:
str = "aaabc", k = 3 

Answer: ""

It is not possible to rearrange the string.
Example 3:
str = "aaadbbcc", k = 2

Answer: "abacabcd"

Another possible answer is: "abcabcda"

The same letters are at least distance 2 from each other.
*/

/* https://leetcode.com/discuss/108174/c-unordered_map-priority_queue-solution-using-cache  */


/* 2017-02-28, update */

    string rearrangeString(string str, int k) {
        
        if (k == 0) return str;
        
        string res;
        int len = str.length();
        
        unordered_map<char, int> map;
        for (auto p : str) map[p]++;
        
        priority_queue<pair<int, char>> q;
        for (auto it : map)
        {
            q.push({it.second, it.first});
        }
        
        while (!q.empty())
        {
            int count = min(len, k);
            vector<pair<int, char>> vec;
            
            for (int i = 0; i < count; i++)
            {
                if (q.empty()) return "";
                
                auto it = q.top();
                q.pop();
                
                res.push_back(it.second);
                
                if (--it.first > 0)
                {
                    vec.push_back(it);
                }
                
                len--;
            }
            
            for (auto p : vec) q.push(p);
        }
        
        return res.empty() ? "0" : res;
      
    }


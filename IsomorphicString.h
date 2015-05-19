/*
  2015-05-19
  bluepp
  May the force be with me!
  
  Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
https://leetcode.com/problems/isomorphic-strings/
*/
  
     bool isIsomorphic(string s, string t) {
        int m = s.size(), n = t.size();
        if (m != n) return false;
        
        unordered_map<char, char> map_s, map_t;
        
        for (int i = 0; i < m; i++)
        {
            if (!map_s.count(s[i])) map_s[s[i]] = t[i];
            else
            {
                if (map_s[s[i]] != t[i]) return false;
            }
            
            if (!map_t.count(t[i])) map_t[t[i]] = s[i];
            else
            {
                if (map_t[t[i]] != s[i]) return false;
            }
        }
        
        return true;
       
    } 

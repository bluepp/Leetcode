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

/* 2016-09-22, update, one map */

    bool isIsomorphic(string s, string t) {
        
        if (s.length() != t.length())
        {
            return false;
        }
        
        unordered_map<char, char> map;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (map.count(s[i]))
            {
                if (map[s[i]] != t[i])
                {
                    return false;
                }
            }
            else
            {
                for (auto it : map)
                {
                    if (it.second == t[i])
                    {
                        return false;
                    }
                }
                
                map[s[i]] = t[i];
            }
        }
        
        return true;

    }
    
    



/* 2016-07-01, a simple one */
    bool isIsomorphic(string s, string t) {
        
        int n = s.length();
        vector<int> m1(256, 0), m2(256, 0);
        
        for (int i = 0; i < n; i++)
        {
            if (m1[s[i]] != m2[t[i]])
            {
                return false;
            }
            
            m1[s[i]] = i+1;
            m2[t[i]] = i+1;
        }
        
        return true;
    }
  
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

/*
  2015-08-11
  bluepp
  May the force be with me!
  
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

https://leetcode.com/problems/valid-anagram/
*/

/* 2018/10/29 */
    bool isAnagram(string s, string t) { 
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> map;
        
        for (auto p : s) {
            map[p]++;
        }
        
        for (auto p : t) {
            if (--map[p] < 0) {
                return false;
            }
        }
        
        return true;
    }



/* 2016-09-27, update */

    bool isAnagram(string s, string t) {
        
        unordered_map<char, int> map;
        
        for (auto p : s)
        {
            map[p]++;
        }
        
        for (auto p : t)
        {
            if (!map.count(p))
            {
                return false;
            }
            else
            {
                map[p]--;
                if (map[p] == 0)
                {
                    map.erase(p);
                }
            }
        }
        
        return map.empty();
    }




    bool isAnagram(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        if (n1 != n2) return false;
        
        unordered_map<char, int> map;
        for (int i = 0; i < n1; i++)
        {
            map[s[i]]++;
        }
        
        for (int i = 0; i < n1; i++)
        {
            if (!map.count(t[i])) return false;
            map[t[i]]--;
            if (map[t[i]] == 0) map.erase(t[i]);
        }
        
        return map.empty();
    }

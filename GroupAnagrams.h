/*
  bluepp
  2015-08-28
  May the force be with me!
  
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.

https://leetcode.com/problems/anagrams/
*/


/* 2016-07-13, update */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> res;
        
        unordered_map<string, vector<string>> map;
        
        for (auto p : strs)
        {
            string t = p;
            sort(t.begin(), t.end());
            
            map[t].push_back(p);
        }
        
        for (auto it : map)
        {
            res.push_back(it.second);
        }
        
        return res;
    }

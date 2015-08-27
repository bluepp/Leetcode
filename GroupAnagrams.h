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

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<int> > map;
        for (int i = 0; i < strs.size(); i++)
        {
            string t = strs[i];
            sort(t.begin(), t.end());
            map[t].push_back(i);
        }
        
        vector<vector<string> > res;
        for (auto p : map)
        {
            vector<string> vec;
            vector<int> t = p.second;
            
            for (auto k : t)
            {
                vec.push_back(strs[k]);
            }
            
            sort(vec.begin(), vec.end());
            res.push_back(vec);
        }
        
        return res;
    }

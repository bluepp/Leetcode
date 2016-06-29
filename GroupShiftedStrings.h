/*
  2015-08-12
  bluepp
  May the force be with me!
  
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". 
We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
Return:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
Note: For the return value, each inner list's elements must follow the lexicographic order.
https://leetcode.com/problems/group-shifted-strings/
*/


/* 2016-06-30, update */
    vector<vector<string>> groupStrings(vector<string>& strings) {
        
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        
        for (auto p : strings)
        {
            string t = "";
            for (char c : p)
            {
                t += to_string((c - p[0] + 26) % 26) + ",";
            }
            
            map[t].push_back(p);
        }
        
        for (auto it = map.begin(); it != map.end(); it++)
        {
            res.push_back(vector<string>(it->second.begin(), it->second.end()));
        }
        
        return res;
    }



/* refer to , https://leetcode.com/discuss/50557/4ms-easy-c-solution-with-explanations */
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string> > map;
        
        for (string s : strings)
        {
            map[shift(s)].push_back(s);
        }
        
        vector<vector<string> > res;
        for (auto m : map)
        {
            vector<string> group = m.second;
            sort(group.begin(), group.end());
            res.push_back(group);
        }
        
        return res;
    }
    
    string shift(string &s)
    {
        string t;
        int n = s.length();
        
        for (int i = 1; i < n; i++)
        {
            int diff = s[i] - s[i-1];
            if (diff < 0) diff += 26;
            t += 'a' + diff;
        }
        
        return t;
    }

/*
    bluepp
    2014-06-26
    2014-12-30
    May the force be with me!
    
     
 Problem:    Substring with Concatenation of All Words
 Source:     https://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/
 Notes:
 You are given a string, S, and a list of words, L, that are all of the same length. Find all 
 starting indices of substring(s) in S that is a concatenation of each word in L exactly once 
 and without any intervening characters.
 For example, given:
 S: "barfoothefoobarman"
 L: ["foo", "bar"]
 You should return the indices: [0,9].
 (order does not matter).

 Solution: ...
*/


/* 2017-01-01, update */

    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> res;
        
        if (s.empty() || words.empty()) return res;
        int m = s.size(), n = words.size(), k = words[0].length();
        
        unordered_map<string, int> need, found;
            
        for (auto p : words)
        {
            need[p]++;
        }
            
        for (int i = 0; i <= m - n * k; ++i)
        {
            found.clear();
            
            int j = 0;
            for (; j < n; ++j)
            {
                string tmp = s.substr(i + j * k, k);
                    
                if (!need.count(tmp) || need[tmp] <= found[tmp]) break;
                    
                found[tmp]++;
            }
            
            if (j == n) res.push_back(i);
        }
        
        return res;
    }

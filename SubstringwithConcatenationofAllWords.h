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

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        int m = s.size(), n = words.size();
        int k = words[0].size();
        
        unordered_map<string, int> need;
        unordered_map<string, int> found;
        
        for (int i = 0; i < n; ++i)
            need[words[i]]++;
            
        for (int i = 0; i <= m - n * k; ++i)
        {
            found.clear();
            int j;
            for (j = 0; j < n; ++j)
            {
                string tmp = s.substr(i + j * k, k);
                auto it = need.find(tmp);
                if (it == need.end())
                    break;
                if (it->second <= found[tmp])
                    break;
                found[tmp]++;
            }
            if (j == n) res.push_back(i);
        }
        return res;
    }

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
        unordered_map<string, int> m1, m2;
        int m = s.length(), n = words.size(), k = words[0].length();
        
        for (auto p : words) m1[p]++;
        
        for (int i = 0; i < m-n*k+1; i++)
        {
            m2.clear();
            
            int j = 0;
            for (; j < n; j++)
            {
                string t = s.substr(i+j*k, k);
                
                if (!m1.count(t) || m2[t] >= m1[t]) break;
                m2[t]++;
            }
            
            if (j == n) res.push_back(i);
        }
        
        return res;
 
    }

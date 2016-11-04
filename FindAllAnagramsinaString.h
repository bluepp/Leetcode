/*
2016-11-05
bluepp
May the force be with me!

https://leetcode.com/problems/find-all-anagrams-in-a-string/

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

    vector<int> findAnagrams(string s, string p) {
        
        if (s.empty()) return {};
        vector<int> res, cnt(128, 0);
        int m = s.size(), n = p.size(), i = 0;
        
        for (char c : p) ++cnt[c];
        
        for (int i = 0; i < m-n+1; i++) {
            
            bool success = true;
            vector<int> tmp = cnt;
            
            for (int j = i; j < i + n; ++j) {
                
                if (--tmp[s[j]] < 0) {
                    success = false;
                    break;
                }
            }
            
            if (success) {
                res.push_back(i); 
            }
            
        }
        
        return res;
        
    }

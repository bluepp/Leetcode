/*
bluepp
2016-06-09
May the force be with me!

https://leetcode.com/problems/word-pattern-ii/

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
Notes:
You may assume both pattern and str contains only lowercase letters.

*/

   unordered_map<char, string> pDict;
    unordered_map<string, char> sDict;

    bool wordPatternMatch(string pattern, string str) {
        
        return _match(pattern, str, 0, 0);
    }
    
    bool _match(string pattern, string str, int i, int j)
    {
        int m = pattern.size();
        int n = str.size();
        
        if (i == m || j == n) {
            if (i == m && j == n)
                return true;
            return false;
        }
        
        bool ins = false;
        for (int k = j; k < n; k++) {
        
            string s = str.substr(j, k - j + 1);
        
            if (pDict.find(pattern[i]) != pDict.end()) {
                if (pDict[pattern[i]] != s)
                    continue;
            } else if (sDict.find(s) != sDict.end()) {
                if (sDict[s] != pattern[i])
                    continue;
            } else {
                pDict[pattern[i]] = s;
                sDict[s] = pattern[i];
                ins = true;
            }
        
            if (_match(pattern, str, i+1,  k + 1))
                return true;
        
            if (ins) {
                pDict.erase(pattern[i]);
                sDict.erase(s);
            }
        }
        
        return false;
        
    }

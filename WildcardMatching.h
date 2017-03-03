/*
2016-06-14
bluepp
May the force be with me!

https://leetcode.com/problems/wildcard-matching/

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

*/

/* https://leetcode.com/discuss/10133/linear-runtime-and-constant-space-solution */

/* 2017-03-03, update */
    bool isMatch(string s, string p) {
        
        int m = s.length(), n = p.length();
        int i = 0, j = 0, asterisk = -1, match;
        
        while (i < m) 
        {
            if (j < n && (s[i] == p[j] || p[j] == '?'))    
            {
                i++;
                j++;
            }
            else if (j < n && p[j] == '*')
            {
                match = i;  
                asterisk = j++;
                
            } 
            else if (asterisk >= 0)
            {
                i = ++match;
                j = asterisk + 1;
            }
            else return false;
        }
        
        while (j < n && p[j] == '*') j++;
        
        return j == n;
      
    }

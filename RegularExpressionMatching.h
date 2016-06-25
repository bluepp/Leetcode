/* 
    bluepp
    2014-06-19
    May the force be with me!
    
    
 Problem:    Regular Expression Matching
 Source:     https://oj.leetcode.com/problems/regular-expression-matching/
 Notes:
 Implement regular expression matching with support for '.' and '*'.
 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.
 The matching should cover the entire input string (not partial).
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 Some examples:
 isMatch("aa","a") ? false
 isMatch("aa","aa") ? true
 isMatch("aaa","aa") ? false
 isMatch("aa", "a*") ? true
 isMatch("aa", ".*") ? true
 isMatch("ab", ".*") ? true
 isMatch("aab", "c*a*b") ? true

 Solution: Both of the two solutions are from http://leetcode.com/2011/09/regular-expression-matching.html .
*/

/* 2016-06-26 , update */

   bool isMatch(string s, string p) {
        
        if (p.empty())
        {
            return s.empty();
        }
        
        if (p.size() == 1)
        {
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        
        if (p[1] != '*')
        {
            if (s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        
        while (!s.empty() && (s[0] == p[0] || p[0] == '.'))
        {
            if (isMatch(s, p.substr(2)))
            {
                return true;
            }
            
            s = s.substr(1);
        }
        
        return isMatch(s, p.substr(2));
        
    }

    bool isMatch(const char *s, const char *p) {
        if (*p == '\0')
            return *s == '\0';
        if (*(p+1) == '*')
        {
            while ((*s == *p || *p == '.') && *s != '\0')
            {
                if (isMatch(s, p+2))
                    return true;
                s++;    
            }
            
            return isMatch(s, p+2);
        }
        
        if (*s == '\0')
            return false;
        return (*s == *p || *p == '.') && isMatch(s+1, p+1);    
        
    }

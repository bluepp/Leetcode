/*
  2015-08-25
  bluepp
  May the force be with me!
  
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it.
Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".
Given "abcd", return "dcbabcd".
https://leetcode.com/problems/shortest-palindrome/
*/

/* 2017-01-04, update */
    string shortestPalindrome(string s) {
        
        string t = s;
        reverse(t.begin(), t.end());
        
        int n = s.size(), i = n;
        
        for (; i >= 0; --i) {
            
            if (s.substr(0, i) == t.substr(n - i)) {
                break;
            }
        }
        
        
        return t.substr(0, n - i) + s;
        
    }


/* https://leetcode.com/discuss/36807/c-8-ms-kmp-based-o-n-time-&-o-n-memory-solution */
/* O(N) */

    string shortestPalindrome(string s) {
    
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;

        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j])
                j = p[j - 1];
            p[i] = (j += l[i] == l[j]);
        }

        return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
    }



/* https://leetcode.com/discuss/40486/accepted-solution-different-based-solution-easy-understand */
/* O(N2) */

    string shortestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;
        
        int longest = 1, start, end;
        for (int begin = 0; begin <= n/2; )
        {
            start = end = begin;
            
            while (end < n-1 && s[end+1] == s[end]) ++end;
            begin = end+1;
            
            while (end < n-1 && start > 0 && s[end+1] == s[start-1])
            {
                ++end;
                --start;
            }
            
            if (start == 0 && longest < end-start+1)
            {
                longest = end-start+1;
            }
        }
        
        string remain = s.substr(longest, n-longest);
        reverse(remain.begin(), remain.end());
        
        return remain+s;
    }

  

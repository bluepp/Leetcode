/*
bluepp
2016-11-07
May the force be with me!

https://leetcode.com/problems/valid-word-abbreviation/

Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".

Note:
Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.

Example 1:
Given s = "internationalization", abbr = "i12iz4n":

Return true.
Example 2:
Given s = "apple", abbr = "a2e":

Return false.

*/

    bool validWordAbbreviation(string word, string abbr) {
        
       int m = word.size(), n = abbr.size();
       int p = 0, cnt = 0;
       
       for (int i = 0; i < n; i++)
       {
           if (abbr[i] >= '0' && abbr[i] <= '9')
           {
               if (cnt == 0 && abbr[i] == '0') return false;
               cnt = cnt * 10 + abbr[i] - '0';
           }
           else
           {
               p += cnt;
               if (p >= m || word[p++] != abbr[i]) return false;
               cnt = 0;
           }
       }
       
       return p + cnt == m;
        
    }

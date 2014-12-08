/*
  bluepp
  2014-12-09
  May the force be with me!
  
  Given two strings S and T, determine if they are both one edit distance apart.
  
  http://www.danielbit.com/blog/puzzle/leetcode/leetcode-one-edit-distance
*/

    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (m > n) return isOneEditDistance(t, s);
        if (n-m > 1) return false;
        
        int i = 0, shift = n-m;
        while (i < m && s[i] == t[i]) i++;
        if (i == m) return shift > 0;
        if (shift == 0) i++;
        while (i < m && s[i] == t[i+shift]) i++;
        return i == m;
    }
  

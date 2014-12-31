/*
  bluepp
  2014-12-31
  May the force be with me!
  
  Given two strings S and T, determine if they are both one edit distance apart.
  
  http://www.danielbit.com/blog/puzzle/leetcode/leetcode-one-edit-distance
*/

/* 2014-12-31, my version */
    bool isOneEditDistance(string s, string t) {
        
        int n1 = s.size(), n2 = t.size();
        if (abs(n1-n2) > 1) return false;
        if (n2 > n1) return isOneEditDistance(t, s);
       
        int i = 0, j = 0;
        while (i < n1 && j < n2 && s[i] == t[j])
        {
            i++;
            j++;
        }
        
        if (n1 == n2) 
        {
            i++;
            j++;
        }
        else i++;
        
        while (i < n1 && j < n2 && s[i]== t[j])
        {
            i++;
            j++;
        }
        
        return (i == n1) && (j == n2);
       
    }


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
  

/*
    bluepp
    
    2014-06-16
    2014-07-17
    2014-09-04
    2014-09-24
    2014-10-23
    2014-10-31
    
    May the force be with me!
  
    Problem:    Minimum Window Substring
    Source:     https://oj.leetcode.com/problems/minimum-window-substring/
    Notes:
    Given a string S and a string T, find the minimum window in S which will contain all the 
    characters in T in complexity O(n).
    For example,
    S = "ADOBECODEBANC"
    T = "ABC"
    Minimum window is "BANC".
    Note:
    If there is no such window in S that covers all characters in T, return the empty string "".
    If there are multiple such windows, you are guaranteed that there will always be only one unique 
    minimum window in S.

    Solution: 1. Use two pointers: start and end. 
              First, move 'end'. After finding all the needed characters, move 'start'.
           2. Use array as hashtable.
 */
 
    string minWindow(string S, string T) {
        int n1 = S.size(), n2 = T.size();
        if (n1 < n2) return "";
        
        int need[256], find[256];
        memset(need, 0, sizeof(need));
        memset(find, 0, sizeof(find));
        
        for (int i = 0; i < n2; i++)
        {
            need[T[i]]++;
        }
       
        int resstart = -1, resend = n1;
        int maxlen = 0;
        int count = 0;
        
        for (int start = 0, end = 0; end < n1; end++)
        {
            if (need[S[end]] == 0) continue;
            
            if (find[S[end]] < need[S[end]]) count++;
            find[S[end]]++;
            
            if (count != n2) continue;
            
            for (; start < end; start++)
            {
                if (need[S[start]] == 0) continue;
                if (find[S[start]] <= need[S[start]]) break;
                find[S[start]]--;
            }
            
            if (end-start < resend-resstart)
            {
                resstart = start;
                resend = end;
            }
            
        }
        
        return resstart == -1 ? "" : S.substr(resstart, resend-resstart+1);
       
    }

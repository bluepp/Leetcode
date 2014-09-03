/*
    bluepp
    
    2014-06-16
    2014-07-17
    2014-09-04
    
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
        int n = S.size(), m = T.size();
        if (n < m)
            return "";
        int need[256] = {0};
        int find[256] = {0};
        for (int i = 0; i < m; i++)
            need[T[i]] ++;
        int count = 0, resStart = -1, resEnd = n;
        
        for (int start = 0, end = 0; end < n; end ++)
        {
            if (need[S[end]] == 0)
                continue;
            if (find[S[end]] < need[S[end]])
                count ++;
            find[S[end]]++;
            if (count != m)
                continue;
            
            for(; start < end; start ++)
            {
                if (need[S[start]] == 0)
                    continue;
                if (find[S[start]] <= need[S[start]])
                    break;
                find[S[start]]--;    
            }
            
            if (end - start < resEnd - resStart)
            {
                resStart = start;
                resEnd = end;
            }
            
        }
        
        return resStart == -1 ? "":S.substr(resStart, resEnd-resStart+1);
        
    }

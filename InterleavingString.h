/*
    bluepp
    
    2014-06-10
    2014-07-14
    2014-12-04
    
    May the force be with me!
 
    Problem:    Interleaving String
    Source:     https://oj.leetcode.com/problems/interleaving-string/
    Notes:
    Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
    For example,
    Given:
    s1 = "aabcc",
    s2 = "dbbca",
    When s3 = "aadbbcbcac", return true.
    When s3 = "aadbbbaccc", return false.

    Solution: 1. dp. O(MN) time & space. 'dp[i][j] == true' means that there is at least one way to construct 
              the string s3[0...i+j-1] by interleaving s1[0...j-1] and s2[0...i-1].
              2. Recursion. Okay for Small but TLE for Large Test data.
 */
 

/* 2017-02-13, update */
    bool isInterleave(string s1, string s2, string s3) {
        
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1+n2 != n3) return false;
        
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        dp[0][0]= true;
        
        for (int i = 1; i <= n1; i++)
        {
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }
        
        for (int j = 1; j <= n2; j++)
        {
            dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
        }
        
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i-1+j]) || (dp[i][j-1] && s2[j-1] == s3[j-1+i]);
            }
        }
        
        return dp[n1][n2];
      
    }
    
    ------------------------------
    
    bool isInterleave(string s1, string s2, string s3) {
        return _isInterleave(s1.c_str(), s2.c_str(), s3.c_str());

    }
    
    bool _isInterleave(const char* s1, const char* s2, const char* s3)
    {
        if (*s1 == '\0' && *s2 == '\0' && *s3 == '\0')
            return true;
        if (*s3 == '\0')
            return false;
        if (*s1 == '\0')
            return strcmp(s2, s3) == 0;
        if (*s2 == '\0')
            return strcmp(s1, s3) == 0;
        
        return *s1 == *s3 && isInterleave(s1+1, s2, s3+1) ||
            *s2 == *s3 && isInterleave(s1, s2+1, s3+1);
    }
    

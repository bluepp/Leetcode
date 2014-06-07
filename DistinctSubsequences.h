/*
    bluepp
    2014-06-07
    May the force be with me!
    
     
    Problem:    Distinct Subsequences
    Source:     https://oj.leetcode.com/problems/distinct-subsequences/
    Notes:
    Given a string S and a string T, count the number of distinct subsequences of T in S.
    A subsequence of a string is a new string which is formed from the original string by deleting 
    some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 
    Here is an example:
    S = "rabbbit", T = "rabbit"
    Return 3.

    Solution: dp.
 */
 
    int numDistinct(string S, string T) {
        int n = S.size(), m = T.size();
        int dp[m+1][n+1];
        
        dp[0][0] = 1;
        for (int j = 1; j <= n; j++)
            dp[0][j] = 1;
        for (int i = 1; i <= m; i++)
            dp[i][0] = 0;
        
        for(int i = 1; i <= m; i++)    
            for (int j = 1; j <= n; j++)
            {
                if (S[j-1] == T[i-1])
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }    
        
        return dp[m][n];    
    
    }

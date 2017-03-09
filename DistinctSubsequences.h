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
 
/* 2017-03-09, update */
    int numDistinct(string s, string t) {
        
        int dp[t.size() + 1][s.size() + 1];
        for (int i = 0; i <= s.size(); ++i) dp[0][i] = 1;    
        for (int i = 1; i <= t.size(); ++i) dp[i][0] = 0;    
        for (int i = 1; i <= t.size(); ++i) {
            for (int j = 1; j <= s.size(); ++j) {
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }
        return dp[t.size()][s.size()];
        
    }

/*
    bluepp
    2014-06-17
    May the force be with me!
    
    Problem:    Palindrome Partitioning II
    Difficulty: Hard
    Source:     https://oj.leetcode.com/problems/palindrome-partitioning-ii/
    Notes:
    Given a string s, partition s such that every substring of the partition is a palindrome.
    Return the minimum cuts needed for a palindrome partitioning of s.
    For example, given s = "aab",
    Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

    Solution: dp. 
    
    http://blog.sina.com.cn/s/blog_b9285de20101iwqt.html
 */
 
 /* WRONG! */
 
    int minCut(string s) {
        int n = s.size();
        bool isPal[n][n];
        int dp[n+1];
        for (int i = 0; i <= n; i++)
            dp[i] = n-i;
       
        for (int i = n-1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if ((s[i] == s[j]) && ((j-i < 2) || isPal[i+1][j-1]))
                {
                    isPal[i][j] = true;
                    dp[i] = min(dp[i], 1 + dp[j+1]);
                }
            }
        }
        
        
        return dp[0] -1;
        
    }

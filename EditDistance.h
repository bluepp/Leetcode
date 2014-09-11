/*
    bluepp
    
    2014-06-08
    2014-07-10
    2014-08-13
    2014-09-11
    
    May the force be with me!
    
    Problem:    Edit Distance
    Source:     https://oj.leetcode.com/problems/edit-distance/
    Notes:
    Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
    You have the following 3 operations permitted on a word:
    a) Insert a character
    b) Delete a character
    c) Replace a character

    Solution: Dynamic Programming.
               1. Time: O(mn) Space: O(mn)
               2. Time: O(mn) Space: O(n);
*/

    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int dp[n+1][m+1];
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;
        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[j-1] == word2[i-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            }
        }
        
        return dp[n][m];
        
    }
    
    
    ----------------------------
    
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int dp[n+1];
        for (int j = 0; j <= n; j++)
            dp[j] = j;
        
        for (int i = 1; i <= m; i++)
        {
            int ulb = dp[0];
            dp[0] = i;
            
            for (int j = 1; j <= n; j++)
            {
                int ul = ulb;
                ulb = dp[j];
                
                if (word1[i-1] == word2[j-1])
                    dp[j] = ul;
                else
                    dp[j] = min(min(dp[j-1], dp[j]), ul) + 1;
                    
            }
        }
        
        return dp[n];
    }
               

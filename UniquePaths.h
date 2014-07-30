/*
    bluepp
    2014-07-01
    2014-07-31
    May the force be with me!
    
     
 Problem:    Unique Paths
 Source:     https://oj.leetcode.com/problems/unique-paths/
 Notes:
 A robot is located at the top-left corner of a m x n grid.
 The robot can only move either down or right at any point in time. The robot is trying to reach 
 the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 How many possible unique paths are there?

 Solution: 
 1. Use formula C(x,t) = t!/(x!*(t-x)!) (x should be large for calculation).
 2. Dynamic programming. UP(i,j) = UP(i-1,j) + UP(i,j-1).
 */
 
 
/* dp */ 
    int uniquePaths(int m, int n) {
        int dp[m][n];
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                dp[i][j] = 0;
        }
        
        dp[m-1][n-1] = 1;
        for (int i = m-2; i >= 0; i--)
            dp[i][n-1] = dp[i+1][n-1];
        
        for(int j = n-2; j >= 0; j--)
            dp[m-1][j] = dp[m-1][j+1];
            
        for (int i = m-2; i >= 0; i--)
        {
            for (int j = n-2; j >= 0; j--)
            {
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        
        return dp[0][0];
        
    }

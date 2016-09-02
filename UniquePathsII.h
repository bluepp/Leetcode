/*
    bluepp
    
    2014-07-01
    2014-07-31
    2014-08-17
    2014-09-16
    
    May the force be with me!
    
 Problem:    Unique Paths II
 Source:     https://oj.leetcode.com/problems/unique-paths-ii/
 Notes:
 Follow up for "Unique Paths":
 Now consider if some obstacles are added to the grids. How many unique paths would there be?
 An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 For example,
 There is one obstacle in the middle of a 3x3 grid as illustrated below.
 [
  [0,0,0],
  [0,1,0],
  [0,0,0]
 ]
 The total number of unique paths is 2.
 Note: m and n will be at most 100.

 Solution: Dynamic programming.
 */
 
/* 2016-09-02. update */

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if (obstacleGrid.empty() || obstacleGrid[0].empty())
        {
            return 0;
        }
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[m-1][n-1] = (obstacleGrid[m-1][n-1] == 1) ? 0 : 1;
        
        for (int i = m-2; i >= 0; i--)
        {
            dp[i][n-1] = (obstacleGrid[i][n-1] == 1) ? 0 : dp[i+1][n-1];

        }
        
        for (int j = n-2; j >= 0; j--)
        {
            dp[m-1][j] = obstacleGrid[m-1][j] == 1 ? 0 : dp[m-1][j+1];
        }
        
        for (int i = m-2; i >= 0; i--)
        {
            for (int j = n-2; j >= 0; j--)
            {
                dp[i][j] = obstacleGrid[i][j] ? 0 : (dp[i+1][j]+dp[i][j+1]);
            }
        }
        
        return dp[0][0];
        
    }


/* My solution */

    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int dp[m][n];
        
        dp[m-1][n-1] = (obstacleGrid[m-1][n-1] == 1) ? 0 : 1;
        for (int i = m-2; i >= 0; i--)
        {
            dp[i][n-1] = (obstacleGrid[i][n-1] == 1) ? 0 : dp[i+1][n-1];
        }
        for (int j = n-2; j >= 0; j--)
        {
            dp[m-1][j] = (obstacleGrid[m-1][j] == 1) ? 0 : dp[m-1][j+1];
        }
        
        for (int i = m-2; i >= 0; i--)
        {
            for (int j = n-2; j >= 0; j--)
            {
                dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : dp[i+1][j] + dp[i][j+1];
            }
        }
        
        return dp[0][0];
        
    }

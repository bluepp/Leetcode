/*
    bluepp
    2014-06-16
    May the force be with me!
    
    Problem:    Minimum Path Sum
    Source:     https://oj.leetcode.com/problems/minimum-path-sum/
    Notes:
    Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right 
    which minimizes the sum of all numbers along its path.
    Note: You can only move either down or right at any point in time.

    Solution: Dynamic Programming. Space O(N).
 */
 
 
/* space O(n) */
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty()) return INT_MIN;
        int M = grid.size(), N = grid[0].size();
        int dp[N];
        dp[0] = grid[0][0];
        for (int i = 1; i < N; ++i)
            dp[i] = grid[0][i] + dp[i-1];
        
        for (int i = 1; i < M; ++i)
        {
            dp[0] += grid[i][0];
            for (int j = 1; j < N; ++j)
                dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
        }
        
        return dp[N-1];
    }
    
   
   
/* my solution, not correct, how to?! */   
    
     int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty())
            return INT_MIN;
        int m = grid.size(), n = grid[0].size();
        
        int dp[m][n];
        for (int i= 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = 0;
                
        vector<int> vec(n, 0);
        grid.push_back(vec);
       
        for (int i = 0; i <= m; i++)
            grid[i].push_back(0);
            
                
                
        dp[0][0] = grid[0][0];
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] += min(grid[i+1][j], grid[i][j+1]);
            }
        }
        
        return dp[m-1][n-1];
                
    }

/*
    bluepp
    
    2014-06-16
    2014-07-17
    2014-09-03
    2014-11-12
    
    May the force be with me!
    
    Problem:    Minimum Path Sum
    Source:     https://oj.leetcode.com/problems/minimum-path-sum/
    Notes:
    Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right 
    which minimizes the sum of all numbers along its path.
    Note: You can only move either down or right at any point in time.

    Solution: Dynamic Programming. Space O(N).
 */

/* runtime error ? why???? */
   int minPathSum(vector<vector<int>>& grid) {
        int minSum = INT_MAX;
        int m = grid.size(), n = grid[0].size();
        
        _dfs(grid, 0, 0, 0, minSum);
        return minSum;
    }
    
    void _dfs(vector<vector<int>> &grid, int i, int j, int sum, int &minSum) {

        if (i == grid.size() && j == grid[0].size()) {
            minSum = min(minSum, sum);
            return;
        }
        
        sum += grid[i][j];
        
        
        _dfs(grid, i+1, j, sum, minSum);
        _dfs(grid, i, j+1, sum, minSum);

    }
 
 
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
    
   
   
   
   
/* 2016-09-02, update */
    
    int minPathSum(vector<vector<int>>& grid) {
        
        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        
        dp[0][0] = grid[0][0];
        
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = dp[i-1][0] + grid[i][0];
            
        }
        
        for (int j = 1; j < n; j++)
        {
            dp[0][j] = dp[0][j-1] + grid[0][j];
            
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[m-1][n-1];
    }

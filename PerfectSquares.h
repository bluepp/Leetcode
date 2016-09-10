/*
  2015-09-11
  bluepp
  May the force be with me!
  
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
https://leetcode.com/problems/perfect-squares/
*/

/* 2016-09-11, update */
    int numSquares(int n) {
        
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; i+j*j <= n; j++)
            {
                dp[i+j*j] = min(dp[i]+1, dp[i+j*j]);
            }
        }
        
        return dp[n];
   
    }
    




   int numSquares(int n) {
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++)
        {
            int t = INT_MAX;
            for (int j = 1; j *j <= i; j++)
            {
                t = min(t, dp[i-j*j]+1);
            }
            
            dp[i] = t;
        }
        
        return dp[n];
    }

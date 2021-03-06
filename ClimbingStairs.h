/*
    bluepp 
    2014-06-05
    2014-08-07
    May the force be with me!
    
   
    Problem:    Climbing Stairs
   
    Source:     https://oj.leetcode.com/problems/climbing-stairs/
    Notes:
    You are climbing a stair case. It takes n steps to reach to the top.
    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

    Solution: Clime one step from last stair or clime 2 steps from the last last stair.
 */


/* 2019/11/01 */

    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n-1];
    }



--------------------
 
    int climbStairs(int n) {
        int steps[n+1];
        
        for (int i = 0; i <= n; i++)
            steps[i] = 0;
        steps[0] = 1;
        steps[1] = 1;
        
        for (int i = 2; i <= n; i++)
            steps[i] = steps[i-1] + steps[i-2];
            
        return steps[n];    
    }
    
    
    
    ------------------
    
    int climbStairs(int n) {
        int last = 1;
        int lastlast = 1;
        for (int i = 2; i <= n; i++)
        {
            int step = last + lastlast;
            lastlast = last;
            last = step;
        }
        return last;
    }
    

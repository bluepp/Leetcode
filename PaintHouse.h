/*
  2015-08-14
  bluepp
  Mayt the force be with me!
  
There are a row of n houses, each house can be painted with one of the three colors: 
red, blue or green. The cost of painting each house with a certain color is different.
You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix.
For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of
painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
https://leetcode.com/problems/paint-house/
*/
/* 2016-07-02, update */

    int minCost(vector<vector<int>>& costs) {
        
        if (costs.empty() || costs[0].empty())
        {
            return 0;
        }
        
        vector<vector<int>> dp = costs;
        
        for (int i = 1; i < costs.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                dp[i][j] += min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
            }
        }
        
        return min(min(dp.back()[0], dp.back()[1]), dp.back()[2]);
    }



/* DP , http://www.cnblogs.com/EdwardLiu/p/4346139.html */

    int minCost(vector<vector<int>>& costs) {
        
        if (costs.empty() || costs[0].empty()) return 0;
        int m = costs.size(), n = costs[0].size();
        
        vector<vector<int> > dp (m+1, vector<int>(n, 0));
        
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = INT_MAX;
            }
        }
        
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (k != j)
                    {
                        dp[i][j] = min(dp[i][j], dp[i-1][k]+costs[i-1][j]);
                    }
                }
            }
        }
        
        int ret = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            ret = min(ret, dp[m][j]);
        }
        
        return ret;
    }

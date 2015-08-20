/*
  2015-08-20
  bluepp
  May the force be with me!
  
There are a row of n houses, each house can be painted with one of the k colors.
The cost of painting each house with a certain color is different.
You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix.
For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the
cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?

https://leetcode.com/problems/paint-house-ii/
*/

/*  https://leetcode.com/discuss/52982/c-dp-time-o-nk-space-o-k */

    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;
        int n = costs.size(), k = costs[0].size();
        if (k == 1) return costs[0][0];
        
        vector<int> dp(k, 0);
        int min1, min2;
        
        for (int i = 0; i < n; i++)
        {
            int min1_old = (i == 0) ? 0 : min1;
            int min2_old = (i == 0) ? 0 : min2;
            
            min1 = INT_MAX;
            min2 = INT_MAX;
            
            for (int j = 0; j < k; j++)
            {
                if (dp[j] != min1_old || min1_old == min2_old)
                {
                    dp[j] = min1_old + costs[i][j];
                }
                else
                {
                    dp[j] = min2_old + costs[i][j];
                }
                
                if (min1 <= dp[j])
                {
                    min2 = min(min2, dp[j]);
                }
                else
                {
                    min2 = min1;
                    min1 = dp[j];
                }
            }
        }
        
        return min1;
    }

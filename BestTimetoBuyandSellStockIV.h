/*
  2015-05-19
  bluepp
  May the force be with me!
  
  Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
*/

/*http://www.cnblogs.com/grandyang/p/4295761.html */


/* 2016-06-11, rewrite */
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        if (n == 0) return 0;
        
        int maxprofit = 0;
        if (k >= n/2)
        {
            for (int i = 1; i < n; i++)
            {
                if (prices[i] > prices[i-1])
                {
                    maxprofit += prices[i]-prices[i-1];
                }
            }
            
            return maxprofit;
        }
        
        
        int local[k+1] = {0};
        int global[k+1] = {0};
        
        for (int i = 1; i < n; i++)
        {
            int diff = prices[i]-prices[i-1];
            
            for (int j = k; j >= 1; j--)
            {
                local[j] = max(global[j-1]+max(diff,0), local[j]+diff);
                global[j] = max(local[j], global[j]);
            }
        }
        
        return global[k];
        
    }




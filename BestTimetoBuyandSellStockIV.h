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
/* https://leetcode.com/discuss/102303/clear-c-solution */

    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        if (n < 2) return 0;
        int ret = 0;
        if (k >= n/2)
        {
            for (int i = 1; i < n; i++)
            {
                if (prices[i] > prices[i-1])
                {
                    ret += prices[i]-prices[i-1];
                }
            }
            
            return ret;
        }
        
        vector<int> buy(k+1, INT_MIN), sale(k+1, 0);
        
        for(int i=0; i<n; i++){
            for(int j=1; j<=k; j++){
            
                buy[j] = max(buy[j], sale[j-1]-prices[i]);
                sale[j] = max(sale[j], buy[j] + prices[i]);
            }
        }
        
        return sale[k];
    }




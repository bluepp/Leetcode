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
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        if (k >= prices.size()) return solve(prices);
        
        int g[k+1] = {0};
        int l[k+1] = {0};
        
        for (int i = 0; i < prices.size()-1; i++)
        {
            int diff = prices[i+1] - prices[i];
            
            for (int j = k; j >= 1; j--)
            {
                l[j] = max(g[j-1] +max(diff, 0), l[j]+diff);
                g[j] = max(g[j], l[j]);
            }
        }
        
        return g[k];
    }
    
    int solve(vector<int> &prices)
    {
        int res = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] - prices[i-1] > 0)
            {
                res += prices[i]-prices[i-1];
            }
        }
        
        return res;
    }



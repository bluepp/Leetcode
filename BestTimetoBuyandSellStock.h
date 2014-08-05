/*
    bluepp
    2014-05-31
    2014-07-06
    2014-08-05
    May the force be with me!
    
    Problem:    Best Time to Buy and Sell Stock
    Source:     https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
    Notes:
    Say you have an array for which the ith element is the price of a given stock on day i.
    If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
    design an algorithm to find the maximum profit.

    Solution: For each element, calculate the max difference with the former elements.
 */
 
    int maxProfit(vector<int> &prices) {
        int maxprofit = 0;
        int min = 0;
        
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < prices[min])
                min = i;
          
            maxprofit = max (maxprofit, prices[i] - prices[min]);
          
        }
        
        return maxprofit;
        
    }


/* 2014-07-06 */
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int min_price = INT_MAX, mprofit = 0;
        
        for (int i = 0; i < n; i ++)
        {
            if (prices[i] < min_price) min_price = prices[i];
            
            if (prices[i] - min_price > mprofit) mprofit = prices[i] - min_price;
        }
        
        return mprofit;
    }

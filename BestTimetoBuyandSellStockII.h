/*
  bluepp
  2014-07-06
  May the force be with me!
  
 Problem:    Best Time to Buy and Sell Stock II
 Source:     https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 Notes:
 Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
 (ie, buy one and sell one share of the stock multiple times). 
 However, you may not engage in multiple transactions at the same time 
 (ie, you must sell the stock before you buy again).

 Solution: 1. At the beginning of the ascending order: buy.
              At the ending of the ascending order: sell.
           2. For ascending order [1,2,4], (4 - 1) == (2 - 1) + (4 - 2).
 */
 
 
/* solution 2 */ 
  int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int mprofit = 0;
        
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i-1])
                mprofit += prices[i] - prices[i-1];
        }
        
        return mprofit;
    }

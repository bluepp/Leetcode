/*
    bluepp
    2014-05-31
    May the force be with me!
    
    Problem:    Best Time to Buy and Sell Stock
    Source:     http://leetcode.com/onlinejudge#question_121
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

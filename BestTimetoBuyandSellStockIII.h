/*
    bluepp
    
    2014-06-01
    2014-07-07
    2014-08-06
    2014-09-07
    
    May the force be with me!
    
    Problem:    Best Time to Buy and Sell Stock III
    Source:     http://leetcode.com/onlinejudge#question_123
    Notes:
    Say you have an array for which the ith element is the price of a given stock on day i.
    Design an algorithm to find the maximum profit. You may complete at most two transactions.
    Note:
    You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

    Solution: dp. max profit =  max { l2r[0...i] + r2l[i+1...N-1] }.
                         0 <= i <= N-1
 */
 
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0 || n == 1) return 0;
        
        int min_price = prices[0], max_price = prices[n-1];
        int maxprofit1[n], maxprofit2[n];
        int maxprofit = 0;
        
        maxprofit1[0] = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] < min_price) min_price = prices[i];
            maxprofit1[i] = max(maxprofit1[i-1], prices[i]-min_price);
        }
        
        maxprofit2[n-1] = 0;
        for (int i = n-2; i >= 0; i--)
        {
            if (prices[i] > max_price) max_price = prices[i];
            maxprofit2[i] = max(maxprofit2[i+1], max_price-prices[i]);
            
            maxprofit = max(maxprofit, maxprofit1[i] + maxprofit2[i]);
        }
        
        return maxprofit;
    }

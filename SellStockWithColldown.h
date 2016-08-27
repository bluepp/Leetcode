/*
bluepp
20116-06-02
May the force be with me!

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:


prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
*/

/* 2016-08-27, update */

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if (n < 2)
        {
            return 0;
        }
        
        vector<int> cooldown(n, 0), sell(n, 0);
        
        sell[1] = prices[1]-prices[0];
        
        for (int i = 2; i < n; i++)
        {
            cooldown[i] = max(sell[i-1], cooldown[i-1]);
            sell[i] = prices[i]-prices[i-1] + max(sell[i-1], cooldown[i-2]);
        }
        
        return max(sell[n-1], cooldown[n-1]);
    }



/* 2016-06-11, dp, update */

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if (n < 2) return 0;
        
        int sell[n] = {0}; // sell[i] means must sell at day i
        int cooldown[n] = {0}; //cooldown[i] means day i is cooldown day
        sell[1] = prices[1]-prices[0];
        
        for (int i = 2; i < n; i++)
        {
            cooldown[i] = max(sell[i-1], cooldown[i-1]);
            sell[i] = prices[i]-prices[i-1] + max(sell[i-1], cooldown[i-2]);
        }
        
        return max(sell[n-1], cooldown[n-1]);
    }



/* 1. make_tuple */

    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        auto buy = -prices.front();
        int sell1 = 0;
        int sell2 = 0;
        
        for (int i = 0; i < prices.size(); i++)
        {
            tie(buy, sell1, sell2) = make_tuple(max(buy, sell2-prices[i]), max(sell1, buy+prices[i]), sell1);
        }
        
        return sell1;
    }
    
    
    /* dp */
    /* https://leetcode.com/discuss/90786/dp-c-solution-8-lines-of-code /
    
        int maxProfit(vector<int>& prices) {
   
        if(prices.size() <= 1) return 0;

        // store the f(n) and f(n-1)
        int res = 0, res_p = 0;
        // store the f'(n)
        int res_ = 0;

        for( unsigned i = 1; i < prices.size(); i++){
            
            res_ = max(res_p, prices[i] - prices[i-1] + res_);
            res_p = res; // NOTE: transfer the value !!
            
            res = max(res, res_);
        }
        
        return res;
    }

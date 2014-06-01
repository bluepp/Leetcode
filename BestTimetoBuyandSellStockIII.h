/*
    bluepp
    2014-06-01
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
 
    for(int i = 1; i < n; i ++)
        {
            if (prices[i] < prices[min])
                min = i;
            int tmp = prices[i] - prices[min];
            if (tmp > lprofit[i-1])
                lprofit[i] = tmp;
            else
                lprofit[i] = lprofit[i-1];
        }
        
        for (int i = n-1; i >= 0; i--)
        {
            if (prices[i] > prices[max])
                max = i;
            int tmp = prices[max] - prices[i];
            if (tmp > rprofit[i+1])
                rprofit[i] = tmp;
            else
                rprofit[i] = rprofit[i+1];
            
            int ktmp = lprofit[i] + rprofit[i];    
            
            if (ktmp > maxprofit)
                maxprofit = ktmp;
                
        }
        
        return maxprofit;
       
    }

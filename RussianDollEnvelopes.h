/*
bluepp
2017-01-07
May the force be with me!

https://leetcode.com/problems/russian-doll-envelopes/

You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
One envelope can fit into another if and only if both the width and height of one envelope is greater than 
the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        
        int ret = 0;
        int n = envelopes.size();
        vector<int> dp(n, 1);
        
        sort(envelopes.begin(), envelopes.end());
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            
            ret = max(ret, dp[i]);
        }
        
        return ret;
    }


/* binary search */

    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        
        vector<int> dp;
        
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        
        for (int i = 0; i < envelopes.size(); ++i) {
            
            int left = 0, right = dp.size(), t= envelopes[i].second;
            
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (dp[mid] < t) left = mid + 1;
                else right = mid;
            }
            
            if (right >= dp.size()) dp.push_back(t);
            else dp[right] = t;
        }
        
        return dp.size();
      
    }








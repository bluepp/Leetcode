/*
2016-06-29
bluepp
May the force be with me!

https://leetcode.com/problems/largest-divisible-subset/

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]

*/

/* 2016-07-18, update */

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<int> dp(n, 0), parent(n, 0);
        vector<int> res;
        
        int mx = 0, mx_idx =0;
        
        for (int i = n-1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    
                    if (mx < dp[i])
                    {
                        mx = dp[i];
                        mx_idx = i;
                    }
                }
            }
        }
    
        for (int i = 0; i < mx; ++i) {
            res.push_back(nums[mx_idx]);
            mx_idx = parent[mx_idx];
        }
        
        return res;
    }




    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        vector<int> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n; i++)
        {
            vector<int> t{nums[i]};
            
            for (int j = i-1; j >= 0; j--)
            {
                if (t.back() % nums[j] == 0)
                {
                    t.push_back(nums[j]);
                }
            }
            
            if (res.size() < t.size())
            {
                res = t;
            }
        }
        
        return res;
    }

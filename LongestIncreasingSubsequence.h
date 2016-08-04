/*
2016-07-25
bluepp
May the force be with me!

https://leetcode.com/problems/longest-increasing-subsequence/

Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> dp;
        
        for (int i = 0; i < nums.size(); i++)
        {
            int l = 0, r = dp.size();
            
            while (l < r)
            {
                int m = l + (r-l)/2;
                
                if (dp[m] < nums[i])
                {
                    l = m+1;
                }
                else
                {
                    r = m;
                }
            }
            
            if (r >= dp.size())
            {
                dp.push_back(nums[i]);
            }
            else
            {
                dp[r] = nums[i];
            }
        }
        
        return dp.size();
    }
    
    /* 2016-08-04 */
    /* o(n), easy understanding */
        int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, 1);
        int ret = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            
            ret = max(ret, dp[i]);
        }
        
        return ret;
    }

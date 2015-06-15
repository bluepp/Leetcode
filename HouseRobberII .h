/*
  2015-06-16
  bluepp
  May the force be with me!
  
Note: This is an extension of House Robber.
After robbing those houses on that street, 
the thief has found himself a new place for his thievery 
so that he will not get too much attention. 
This time, all houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. 
Meanwhile, the security system for these houses remain the same as 
for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

https://leetcode.com/problems/house-robber-ii/
*/

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n-1; i++)
        {
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        int ret1 = dp[n-2];
        
        memset(dp, 0, sizeof(dp));
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        
        for (int i = 3; i < n; i++)
        {
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        int ret2 = dp[n-1];
        
        int ret = max(ret1, ret2);
        
        return ret;
    }

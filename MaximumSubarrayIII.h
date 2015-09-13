/*
  2015-09-13
  bluepp
  May the force be with me!

Given an array of integers and a number k, find k non-overlapping subarrays which have the largest sum.
The number in each subarray should be contiguous.
Return the largest sum.

Have you met this question in a real interview? Yes
Example
Given [-1,4,-2,3,-2,3], k=2, return 8
http://www.lintcode.com/en/problem/maximum-subarray-iii/#
*/

    int maxSubArray(vector<int> nums, int k) {
        // write your code here
        int n = nums.size();
        int dp[n+1][k+1];
        memset(dp, 0, sizeof(dp));
        
        for (int j = 1; j <= k; j++)
        {
            for (int i = j; i <= n; i++)
            {
                dp[i][j] = INT_MIN;
                
                int endMax = 0;
                int maxval = INT_MIN;
                
                for (int p = i-1; p >= j-1; p--)
                {
                    endMax = max(nums[p], endMax+nums[p]);
                    maxval = max(maxval, endMax) ;
                    
                    if (dp[i][j] < dp[p][j-1]+maxval)
                    {
                        dp[i][j] = dp[p][j-1]+ maxval;
                    }
                }
            }
        }
        
        return dp[n][k];
    }

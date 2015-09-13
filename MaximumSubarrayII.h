/*
  bluepp
  2015-09-13
  May the force be with me!
  
Given an array of integers, find two non-overlapping subarrays which have the largest sum.
The number in each subarray should be contiguous.
Return the largest sum.

Have you met this question in a real interview? Yes
Example
For given [1, 3, -1, 2, -1, 2], the two subarrays are [1, 3] and [2, -1, 2] or [1, 3, -1, 2] and [2],
they both have the largest sum 7.
http://www.lintcode.com/en/problem/maximum-subarray-ii/#
*/

    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int n = nums.size();
        
        int sum1 = 0, maxsum1 = INT_MIN;
        int dp1[n];
        memset(dp1, 0, sizeof(dp1));
        
        for(int i = 0; i < n; i++)
        {
            sum1 = max(sum1+nums[i], nums[i]);
            maxsum1 = max(maxsum1, sum1);
            dp1[i] = maxsum1;
        }
        
        int dp2[n];
        memset(dp2, 0, sizeof(dp2));
        dp2[n-1] = nums[n-1];;
        int sum2 = 0, maxsum2 = INT_MIN;
        for (int i = n-1; i >= 0; i--)
        {
            sum2 = max(nums[i], sum2+nums[i]);
            maxsum2 = max(maxsum2, sum2);
            dp2[i] = maxsum2;
        }
        
        int ret = INT_MIN;
        for (int i = 0; i < n-1; i++)
        {
            ret = max(ret, dp1[i] + dp2[i+1]);
        }
        
        return ret;
    }

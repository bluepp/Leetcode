/*
    bluepp
    
    2014-06-14
    2014-07-16
    2014-09-02
    2014-09-18
    2015-05-08
    
    May the force be with me!
    
    Problem:    Maximum Subarray
    Source:     https://oj.leetcode.com/problems/maximum-subarray/
    Notes:
    Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
    For example, given the array [-2,1,-3,4,-1,2,1,-5,4], the contiguous subarray [4,-1,2,1] has the largest sum = 6.

    Solution: dp.
 */
 
 
 /* 2015-05-08 */
     int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        bool bneg = true;
        
        int max_sum = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (bneg && nums[i] > 0) bneg = false;
            
            sum += nums[i];
            if (sum < 0) sum = 0;
            
            max_sum = max(max_sum, sum);
        }
       
        if (bneg)
        {
            max_sum = nums[0];
            for (int i = 1; i < n; i++)
            {
                max_sum = max(max_sum, nums[i]);
            }
        }
        
        return max_sum;
    }
 
 
 
 /* 2014-09-18 , my version */
 
   int maxSubArray(int a[], int n) {
        
        int sum = a[0];
        int ret = a[0];
        
        for (int i = 1; i < n; i++)
        {
            sum = max(a[i], sum+a[i]);
            ret = max(ret, sum);    
        }
        
        return ret;
    }

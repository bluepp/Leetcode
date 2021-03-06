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
 
 /* 2016-08-26, update */
 
     int maxSubArray(vector<int>& nums) {
        
        int ret = INT_MIN, sum = 0;
        
        for (auto p : nums)
        {
            sum = max(sum+p, p);
            ret = max(ret, sum);
        }
        
        return ret;
    }
 
 
 /* 2016-07-12 , update */
    int maxSubArray(vector<int>& nums) {
        
        int ret = nums[0], t = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            t = max(t+nums[i], nums[i]);
            ret = max(ret, t);
        }
        
        return ret;
       
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

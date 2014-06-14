/*
    bluepp
    2014-06-14
    May the force be with me!
    
    Problem:    Maximum Subarray
    Source:     https://oj.leetcode.com/problems/maximum-subarray/
    Notes:
    Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
    For example, given the array [-2,1,-3,4,-1,2,1,-5,4], the contiguous subarray [4,-1,2,1] has the largest sum = 6.

    Solution: dp.
 */
 
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

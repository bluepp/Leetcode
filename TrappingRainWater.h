/*
    bluepp
    
    2014-06-30
    2014-08-01
    2014-08-18
    2014-08-27
    2014-09-08
    2014-09-20
    2014-11-10
    
    May the force be with me!
    
    
 Problem:    Trapping Rain Water
 Source:     https://oj.leetcode.com/problems/trapping-rain-water/
 Notes:
 Given n non-negative integers representing an elevation map where the width of 
 each bar is 1, compute how much water it is able to trap after raining.
 For example, 
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

 Solution: Find left bound and right bound for each element. O(n).
*/


/* 2016-08-31, update */
    int trap(vector<int>& height) {
        
        int n = height.size();
        if (n == 0)
        {
            return 0;
        }
        
        vector<int> left(n, 0), right(n, 0);
        
        int lmax = height[0];
        for (int i = 0; i < n; i++)
        {
            lmax = max(lmax, height[i]);
            left[i] = lmax;
        }
        
        int rmax = height[n-1];
        for (int i = n-1; i >= 0; i--)
        {
            rmax = max(rmax, height[i]);
            right[i] = rmax;
        }
        
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            ret += min(left[i], right[i]) - height[i];
        }
        
        return ret;
    }

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

/* 2017-01-09, update */
    int trap(vector<int>& height) {
        
        int n = height.size();
        if (n == 0)
        {
            return 0;
        }
        
        vector<int> left(n, 0), right(n, 0);
        
        int lmax = INT_MIN, rmax = INT_MIN;
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            lmax = max(lmax, height[i]);
            left[i] = lmax;
        }
        
        for (int i = n-1; i >= 0; i--)
        {
            rmax = max(rmax, height[i]);
            right[i] = rmax;
            
            ret += min(left[i], right[i])-height[i];
        }
        
        return ret;
    }




/* another one */

    int trap(vector<int>& height) {
        
        int res = 0, l = 0, r = height.size() - 1;
        
        while (l < r) {
            
            int mn = min(height[l], height[r]);
            if (mn == height[l]) {
                ++l;
                while (l < r && height[l] < mn) {
                    res += mn - height[l++];
                }
            } else {
                --r;
                while (l < r && height[r] < mn) {
                    res += mn - height[r--];
                }
            }
        }
        
        return res;
    }

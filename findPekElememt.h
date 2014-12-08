/*
  bluepp
  
  2014-12-08
  
  May the force be with me !
  
https://oj.leetcode.com/problems/find-peak-element/  
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/

    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        if (n == 0 || n == 1) return 0;
        
        int l = 0, r = n-1;
        while (l <= r)
        {
            int m = l + (r-l)/2;
            if (m < r && m > l && num[m] > num[m+1] && num[m] > num[m-1]) return m;
            
            if (m == r && m > l && num[m] > num[m-1]) return m;
            if (m == l && m < r && num[m] > num[m+1]) return m;
            
            if (num[l] < num[r]) l++;
            else r--;
        }
        
        return l+(r-l)/2;
    }

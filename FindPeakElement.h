/*
  2014-12-10
  bluepp
  May the froce be with me!
  
  https://oj.leetcode.com/problems/find-peak-element/
  
 A peak element is an element that is greater than its neighbors.
Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/



/* 2017-02-25, my update */
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        int l = 0, r = n-1;
        
        while (l < r)
        {
            int m = l + (r-l)/2;
            
            if (m < r && nums[m] < nums[m+1]) l = m+1;
            else r = m;
        }
        
        return l;
    }


/* https://leetcode.com/discuss/96588/general-binary-search-in-java */
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        int lo = 0, hi = n - 1;
        
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if(nums[mid] < nums[mid+1]) {
                lo = mid + 1; 
            } else {
                hi = mid;
            }
        }
    
        return lo;
       
    }



    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        int left = 0, right = n - 1,mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if ((mid == 0 || num[mid-1] <= num[mid]) && (mid == n -1 || num[mid+1] <= num[mid]))
                return mid;
            if (mid > 0 && num[mid - 1] > num[mid]) {
                right = mid - 1;
            } else if (num[mid + 1] > num[mid]) {
                left = mid + 1;
            }
        }
        return mid;
    }


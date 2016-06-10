/*
    bluepp
    2014-06-23
    2014-07-24
    2014-08-21
    May the force be with me!
    
   
 Problem:    Search in Rotated Sorted Array II
 Source:     https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 What if duplicates are allowed?
 Would this affect the run-time complexity? How and why?
 Write a function to determine if a given target is in the array.

 Solution: Sequence search. O(n)
           Since there are duplicates, it's hard to decide which branch to go if binary-search is deployed.
 */
 
 
    bool search(int a[], int n, int target) {
        
        for (int i = 0; i < n; i++)
        {
            if (a[i] == target)
                return true;    
        }
        
        return false;
    }


/* 2016-06-11, add binary search */
/* https://leetcode.com/discuss/94293/simple-c-solution-explained */

   bool search(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size() - 1;        
        while(l <= r){  
            int mid = l + (r - l) / 2;            
            if(nums[mid] == target) return true;
            if(nums[mid] > nums[r]){
                if(target > nums[mid] || target <= nums[r]) l = mid + 1;    
                else r = mid - 1;                                                               
            }else if(nums[mid] == nums[r]){
                r --;   // may cause linear time here, e.g. [7, 8, 9, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], search for 0
            }
            else{
                if(target <= nums[r] && target > nums[mid]) l = mid + 1; 
                else r = mid - 1;                                                               
            }
        }
        return false;   
    }

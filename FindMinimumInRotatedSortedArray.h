/*
  bluepp
  
  2014-11-23
  2014-12-06
  
 Problem:    Find Minimum in Rotated Sorted Array
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 Find the minimum element.
 You may assume no duplicate exists in the array.
*/

    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0, r = n-1;
        while (l < r && nums[l] > nums[r])
        {
            int m = l + (r-l)/2;
            
            if (nums[m] > nums[r])
            {
                l = m+1;
            }
            else
            {
                r = m;
            }
        }
        
        return nums[l];        
    }

/*
    bluepp
    
    2014-06-23
    2014-07-24
    2014-08-21
    2014-10-23
    2014-11-15
    
    May the force be with me!
    
    
 Problem:    Search in Rotated Sorted Array
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_33
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 You are given a target value to search. If found in the array return its index, otherwise return -1.
 You may assume no duplicate exists in the array.

 Solution: Binary search. O(lgn) eg. [4 5 6] -7- 8 1 2, 5 6 0 -1- [2 3 4]
 */
 
 /* 2017-03-01, update */

    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        
        int l = 0, r = nums.size()-1;
        
        while (l <= r)
        {
            int m = l + (r-l)/2;
            
            if (nums[m] == target) return m;
            else if (nums[m] < nums[r])
            {
                if (target > nums[m] && target <= nums[r]) l = m+1;
                else r = m-1;
            }
            else
            {
                if (target >= nums[l] && target < nums[m]) r = m-1;
                else l = m+1;
            }
        }
        
        return -1;
        
    }

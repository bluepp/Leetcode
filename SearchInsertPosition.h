/*
    bluepp
    2014-06-22
    2014-07-23
    2014-08-22
    2014-10-21
    May the force be with me!
    
    
 Problem:    Search Insert Position
 Source:     https://oj.leetcode.com/problems/search-insert-position/
 Notes:
 Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 You may assume no duplicates in the array.
 Here are few examples.
 [1,3,5,6], 5 -> 2
 [1,3,5,6], 2 -> 1
 [1,3,5,6], 7 -> 4
 [1,3,5,6], 0 -> 0

 Solution: Binary search.
 */
 
    int searchInsert(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size()-1;
        while (l <= r)
        {
            int m = l + (r-l)/2;
            if (nums[m] == target)
                return m;
            
            if (nums[m] < target)
                l = m+1;
            else r = m - 1;    
        }
        
        return l;
        
    }

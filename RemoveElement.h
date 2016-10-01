/*
    bluepp
    2014-06-20
    2014-07-22
    2014-08-28
    May the force be with me!

 Problem:    Remove Element
 Source:     https://oj.leetcode.com/problems/remove-element/
 Notes:
 Given an array and a value, remove all instances of that value in place and return the new length.
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.

 Solution: Refactor: Update solution. Use two pointers.
 */
 
/* 2016-10-02 , update */

    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        int idx = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != val)
            {
                nums[idx++] = nums[i];
            }
        }
        
        return idx;
    }

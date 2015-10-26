/*
  2015-10-27
  bluepp
  May the force be with me!
  
Given an array nums, write a function to move all 0's to the end of it while maintaining
the relative order of the non-zero elements.
For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
https://leetcode.com/problems/move-zeroes/
*/

   void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                nums[index++] = nums[i];
            }
        }
        
        for (int i = index; i < n; i++)
        {
            nums[i] = 0;
        }
    }

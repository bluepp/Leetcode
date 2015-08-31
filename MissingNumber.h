/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity.
Could you implement it using only constant extra space complexity?
https://leetcode.com/problems/missing-number/
*/

    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++)
        {
            while (nums[i] != i)
            {
                if (nums[i] < 0 || nums[i] >= n) break;
                swap(nums[i], nums[nums[i]]);
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if (i != nums[i]) return i;
        }
        
        return n;
    }
/*
bluepp
2017-02-20
May the force be with me!

https://leetcode.com/problems/target-sum/?tab=Description

You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/


    int findTargetSumWays(vector<int>& nums, int S) {
        
        int ret = 0;
        _sum(nums, S, 0, ret);
        
        return ret;
    }
    
    void _sum(vector<int> &nums, int S, int start, int &ret)
    {
        if (start >= nums.size())
        {
            if (S == 0) ret++;
            return;
        }
        
        _sum(nums, S-nums[start], start+1, ret);
        _sum(nums, S+nums[start], start+1, ret);
    }

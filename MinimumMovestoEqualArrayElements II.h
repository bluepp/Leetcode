/*
bluepp
2016-11-28
May the force be with me!

https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
*/

/* 2017-03-10, update */
    int minMoves2(vector<int>& nums) {
        
        int ret = 0;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        int mid = nums[n/2];
        
        for (auto p : nums)
        {
            ret += abs(p-mid);
        }
        
        return ret;
    }




    int minMoves2(vector<int>& nums) {
        
        int ret = 0;
        sort(nums.begin(), nums.end());
        
        int l = 0, r = nums.size()-1;
        while (l < r)
        {
            ret += nums[r]-nums[l];
            
            l++;
            r--;
        }
        
        return ret;
    }

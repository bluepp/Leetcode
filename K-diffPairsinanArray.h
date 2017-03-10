/*
bluepp
2017-03-10
May the force be with me!

https://leetcode.com/problems/k-diff-pairs-in-an-array/?tab=Description

Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. 
Here a k-diff pair is defined as an integer pair (i, j), 
where i and j are both numbers in the array and their absolute difference is k.

Example 1:
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:
Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:
Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
*/

    int findPairs(vector<int>& nums, int k) {
        
        int ret = 0;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            for (int j = i+1; j < n; j++)
            {
                if (nums[j]-nums[i] == k) 
                {
                    ret++;
                    break;
                }
            }
        }
        
        return ret;
    }

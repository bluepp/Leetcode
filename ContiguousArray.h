/*
bluepp
2017-03-13
May the force be with me!

https://leetcode.com/problems/contiguous-array/#/description

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

*/

    int findMaxLength(vector<int>& nums) {
        
        int res = 0, n = nums.size(), sum = 0;
        unordered_map<int, int> m{{0, -1}};
        
        for (int i = 0; i < n; ++i) {
            
            sum += (nums[i] == 1) ? 1 : -1;
            if (m.count(sum)) {
                res = max(res, i - m[sum]);
            } else {
                m[sum] = i;
            }
        }
        
        return res;
    }

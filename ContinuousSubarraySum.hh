/*
bluepp
2017-03-11
May the force be with me!

https://leetcode.com/problems/continuous-subarray-sum/?tab=Description

Given a list of non-negative numbers and a target integer k, 
write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, 
that is, sums up to n*k where n is also an integer.

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.

*/

    bool checkSubarraySum(vector<int>& nums, int k) {
        
       int n = nums.size(), sum = 0;
        unordered_map<int, int> m{{0,-1}};
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int t = (k == 0) ? sum : (sum % k);
            if (m.count(t)) {
                if (i - m[t] > 1) return true;
            } else m[t] = i;
        }
        return false;
        
    }

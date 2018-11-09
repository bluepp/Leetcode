/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2

*/

    int subarraySum(vector<int>& nums, int k) {
        int ret = 0;
        unordered_map<int, int> map;
        map[0]++;
        
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if (map.count(sum-k)) {
                ret += map[sum-k];
            } 
            
            map[sum]++;
        }
        
        return ret;      
    }

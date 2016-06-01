/*
bluepp
2016-06-01
May the force be with me!

https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?
*/

    int maxSubArrayLen(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;
        map[0] = -1;
        int ret = 0;
        
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            if (!map.count(sum))
            {
                map[sum] = i;
            }
            
            if (map.count(sum-k))
            {
                ret = max(ret, i-map[sum-k]);
            }
        }
        
        return ret;
        
    }

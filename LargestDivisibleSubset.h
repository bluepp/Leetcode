/*
2016-06-29
bluepp
May the force be with me!

https://leetcode.com/problems/largest-divisible-subset/

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]

*/

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        vector<int> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n; i++)
        {
            vector<int> t{nums[i]};
            
            for (int j = i-1; j >= 0; j--)
            {
                if (t.back() % nums[j] == 0)
                {
                    t.push_back(nums[j]);
                }
            }
            
            if (res.size() < t.size())
            {
                res = t;
            }
        }
        
        return res;
    }

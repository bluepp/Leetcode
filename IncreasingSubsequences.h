/*
bluepp
2017-03-04
May the force be with me!

https://leetcode.com/problems/increasing-subsequences/?tab=Description

Given an integer array, your task is to find all the different possible increasing subsequences of the given array, 
and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequenc
*/

   vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<int> vec;
        set<vector<int>> set;
        
        int n = nums.size();
        
        for (int i = 2; i <= n; i++)
        {
            _dfs(nums, 0, i, vec, set);
        }
        
        return vector<vector<int>> (set.begin(), set.end());
    }
    
    void _dfs(vector<int> &nums, int start, int len, vector<int> vec, set<vector<int>> &set)
    {
        if (vec.size() == len)
        {
            set.insert(vec);
            return;
        }
        
        for (int i = start; i < nums.size(); i++)
        {
            if (vec.size() && nums[i] < vec.back()) continue;
            
            vec.push_back(nums[i]);
            _dfs(nums, i+1, len, vec, set);
            vec.pop_back();
        }
        
    }

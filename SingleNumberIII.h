/*
  2015-08-17
  bluepp
  May the force be with me!
  
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements
appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

*/

/* not constant space, how ? */
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        
        for (int i = 0; i < n; i++)
        {
            if (map.count(nums[i])) map.erase(nums[i]);
            else map[nums[i]] = i;
        }
        
        vector<int> vec;
        for (auto p : map)
        {
            vec.push_back(p.first);
        }
        
        return vec;
    }

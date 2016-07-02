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

/* linear time, constant space, https://leetcode.com/discuss/48119/single-number-iii?show=48119#q48119 */
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            x ^= nums[i];
        }
        
        int t = 1;
        for (int i = 0; i < 32; i++)
        {
            t <<= i;
            if (t & x) break;
        }
        
        int x1 = 0, x2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (t & nums[i])
            {
                x1 ^= nums[i];
            }
            else
            {
                x2 ^= nums[i];
            }
        }
        
       return {x1, x2}; // 2016-07-02, update
    }


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

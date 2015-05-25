/*
  2015-05-25
  bluepp
  May the force be with me!
  
  Given an array of integers, find if the array contains any duplicates. 
  Your function should return true if any value appears at least twice in the array, 
  and it should return false if every element is distinct
  https://leetcode.com/problems/contains-duplicate/
*/

    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;
        
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            if (map.count(nums[i])) return true;
            map[nums[i]] ++;
        }
        
        return false;
    }

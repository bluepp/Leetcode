/*
  bluepp
  2015-06-01
  2015-06-10
  May the force be with me!
  
  Given an array of integers and an integer k, 
  find out whether there there are two distinct indices i and j in 
  the array such that nums[i] = nums[j] and the difference between i and j is at most k
  https://leetcode.com/problems/contains-duplicate-ii/
*/

/* 2015-06-10 */
   bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        
        for (int i = 0; i < n; i++)
        {
            if (map.count(nums[i]) && (i-map[nums[i]]) <= k)
            {
               return true;
            }
            else
            {
                map[nums[i]] = i;
            }
        }
        
        return false;
    }


    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> table;
        
        for (int i = 0; i < n; i++)
        {
            if (!table.count(nums[i])) table[nums[i]] = i;
            else
            {
                if (i - table[nums[i]] <= k) return true;
                table[nums[i]] = i;
            }
        }
        
        return false;
    }

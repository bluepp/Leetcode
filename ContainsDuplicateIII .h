/*
  2015-06-12
  bluepp
  May the force be with me!
 
  Given an array of integers, find out whether there are two distinct 
  indices i and j in the array such that the difference between nums[i] and nums[j] 
  is at most t and the difference between i and j is at most k.
  
  https://leetcode.com/problems/contains-duplicate-iii/
*/

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if (n < 2 || k == 0) return false;
        
        deque<int> q;
        multiset<long> windows;
        
        for (int i = 0; i < n; i++)
        {
            if (windows.size() > k)
            {
                int num = q.front();
                q.pop_front();
                windows.erase(windows.find(num));
            }
            
            auto it = windows.lower_bound((long)nums[i] - (long)t);
            if (it == windows.end() || *it > (long)nums[i] + (long)t)
            {
                q.push_back(nums[i]);
                windows.insert(nums[i]);
            }
            else 
                return true;
        }
        
        return false;
    }

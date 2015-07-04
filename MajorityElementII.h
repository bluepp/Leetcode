/*
  2015-07-05
  bluepp
  May the force be with me!
  
  Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
  The algorithm should run in linear time and in O(1) space.
  
  https://leetcode.com/problems/majority-element-ii/
  */
  
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> res;
        int m = 0, n = 0, cm = 0, cn = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == m) cm++;
            else if (nums[i] == n) cn++;
            else if (cm == 0)
            {
                m = nums[i];
                cm = 1;
            }
            else if (cn == 0)
            {
                n = nums[i];
                cn = 1;
            }
            else
            {
                cm --;
                cn--;
            }
        }
        
        cm = cn = 0;
        for (auto &a : nums)
        {
            if (a == m)
            {
                cm++;
            }
            else if (a == n)
            {
                cn++;
            }
        }
        
        if (cm > nums.size() /3)
        {
            res.push_back(m);
        }
        if (cn > nums.size() / 3)
        {
            res.push_back(n);
        }
        
        return res;
        
    }  

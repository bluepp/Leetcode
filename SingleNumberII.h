/*
    bluepp
    
    2014-06-24
    2014-07-26
    2014-08-20
    2014-11-05
    
    May the force be with me!
    
    
 Problem:    Single Number II
 Source:     http://oj.leetcode.com/problems/single-number-ii/
 Notes:
 Given an array of integers, every element appears three times except for one. 
 Find that single one.
 Your algorithm should have a linear runtime complexity. Could you implement it 
 without using extra memory?

 Solution: Count the number of each bit.
*/

    int singleNumber(vector<int>& nums) {
        
        int ret = 0;
        int n = nums.size();
        
        for (int i = 0; i < 32; i++)
        {
            int count = 0;
            int bit = 1 << i;
            for (auto p : nums)
            {
                if (bit & p) count++;
            }
            
            if (count % 3 != 0) ret |= bit;
        }
        
        return ret;
        
    }

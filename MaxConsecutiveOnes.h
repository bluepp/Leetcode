/*
bluepp
2017-02-13
May the force be with me!

https://leetcode.com/problems/max-consecutive-ones/

Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
 */    
 
 
     int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        int ret = 0, sum = 0;
        
        for (auto p : nums)
        {
            if (p == 0) sum = 0;
            else sum += p;
            
            ret = max(ret, sum);
        }
        
        return ret;
    }

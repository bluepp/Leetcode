/*
  bluepp
  2014-12-22
  May the force be with me!

https://oj.leetcode.com/problems/majority-element/  
Majority Element Total Accepted: 1192 Total Submissions: 3143 My Submissions Question Solution 
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
*/

/* 2016-09-11, update */
    int majorityElement(vector<int>& nums) {
        
        int ret = 0;
        int count = 0;
        
        for (auto p : nums)
        {
            if (p == ret)
            {
                count++;
            }
            else if (count == 0) 
            {
                ret = p;
                count = 1;
            }
            else
            {
                count --;
            }
        }
        
        return ret;
      
    }



    int majorityElement(vector<int> &num) {
        int n = num.size();
        
        int index = 0, count = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (num[index] == num[i]) count++;
            else count --;
            
            if (count == 0) 
            {
                index = i;
                count = 1;
            }
        }
        
        return num[index];
    }

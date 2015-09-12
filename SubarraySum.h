/*
  2015-09-12
  bluepp
  May the force be with me!
  
  Easy Subarray Sum Show result 

Given an integer array, find a subarray where the sum of numbers is zero.
Your code should return the index of the first number and the index of the last number.

Have you met this question in a real interview? Yes
Example
Given [-3, 1, 2, -3, 4], return [0, 2] or [1, 3]
http://www.lintcode.com/en/problem/subarray-sum/#

*/

    vector<int> subarraySum(vector<int> nums){
        // write your code here
        unordered_map<int, int> map;
        int sum = 0;
        vector<int> vec;
      
        map[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (map.count(sum))
            {
                vec = {map[sum]+1, i};
            }
            
            map[sum] = i;
        }
        
        return vec;
    }

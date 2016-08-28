/*
  bluepp
  2014-12-20
  May the force be with me!
  
https://oj.leetcode.com/problems/two-sum-ii-input-array-is-sorted/  
  Two Sum II - Input array is sorted Total Accepted: 161 Total Submissions: 345 My Submissions Question Solution 
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

/* 2016-08-29, update */
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> ret;
        
        int l = 0, r = numbers.size()-1;
        while (l < r)
        {
            int t = numbers[l] + numbers[r];
            
            if (t == target)
            {
                return {l+1, r+1};
            }
            else if (t < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        
        return {};
    }
    
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        
        vector<int> vec;
        int n = numbers.size();
        int l = 0, r = n-1;
        int t1 = -1, t2 = -1;
        
        while (l < r)
        {
            int tmp = numbers[l]+numbers[r];
            
            if (tmp == target)
            {
                t1 = l+1;
                t2 = r+1;
                break;
            }
            else if (tmp < target) l++;
            else r--;
        }
        
        vec.push_back(t1);
        vec.push_back(t2);
        
        return vec;
    }

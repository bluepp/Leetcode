/*
bluepp
2016-12-30
May the force be with me!

https://leetcode.com/problems/find-all-duplicates-in-an-array/

Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

*/

/* 1 */
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++)
        {
            int idx = abs(nums[i])-1;
            
            if (nums[idx] < 0) res.push_back(idx+1);
            
            nums[idx] = -nums[idx];
        }
        
        return res;
        
    }
    
 /* 2 */
     vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> res;
        
        for(int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != nums[nums[i]-1])
            {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i+1)
            {
                res.push_back(nums[i]);
            }
        }
        
        return res;
        
    }
    

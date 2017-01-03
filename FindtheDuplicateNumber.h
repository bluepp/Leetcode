/*
bluepp
2017-01-04
May the force be with me!

https://leetcode.com/problems/find-the-duplicate-number/

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

   int findDuplicate(vector<int>& nums) {
        
        int l = 1, r = nums.size()-1;
        
        while (l < r)
        {
            int m = l + (r-l)/2;
            
            int cnt = 0;
            for (auto p : nums)
            {
                if (p <= m) cnt++;
            }
            
            if (cnt <= m) l = m+1;
            else r = m;
        }
        
        return l;
       
    }

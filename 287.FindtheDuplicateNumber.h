/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

    int findDuplicate(vector<int>& nums) {
        int ret = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i])-1;
            
            if (nums[index] < 0) {
                ret = abs(nums[i]);
                break;
            }
            
            nums[index] = -nums[index];
            
        }
        
        return ret;
    }


/* ologn */
    int findDuplicate(vector<int>& nums) {
        
        int l = 0, r = nums.size()-1;
        
        while (l < r) {
            int m = l + (r-l)/2;
            
            int count = 0;
            for (auto p : nums) {
                if (p <= m) {
                    count ++;
                }
            }
            
            if (count <= m) {
                l = m+1;
            } else {
                r = m;
            }
            
        }
        
        
        return r;
      
    }

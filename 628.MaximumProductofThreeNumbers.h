/*
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
*/

    int maximumProduct(vector<int>& nums) { 
      
        int mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN;
        int mn1 = INT_MAX, mn2 = INT_MAX;
        
        for (auto p : nums) {
            if (p > mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = p;
            } else if (p > mx2) {
                mx3 = mx2;
                mx2 = p;
            } else if (p > mx3) {
                mx3 = p;
            }
            
            if (p < mn1) {
                mn2 = mn1;
                mn1 = p;
            } else if (p < mn2) {
                mn2 = p;
            }
        }
        
        int ret = max(mx1 * mx2 * mx3, mn1 * mn2 * mx1);
        return ret;
    }

/* ------------------------------------------------------------- */

    int maximumProduct(vector<int>& nums) { 
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int p1 = nums[n-1] * nums[n-2] * nums[n-3];
        int p2 = nums[n-1] * nums[1] * nums[0];
        
        return max(p1, p2);     
    }

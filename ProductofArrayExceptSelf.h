/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] 
is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].
https://leetcode.com/problems/product-of-array-except-self/
*/


/* 2017-01-01, update */

    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> res(nums.size(), 1);
        
        for (int i = 1; i < nums.size(); ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] *= right;
            right *= nums[i];
        }
        
        return res;
    }



/* 2016-09-02, update */

    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> vec(n, 1);

        int p = 1;
        for (int i = 1; i < n; i++)
        {
            p = p * nums[i-1];
            vec[i] = p;
        }
        
        p = 1;
        for (int i = n-2; i >= 0; i--)
        {
            p = p * nums[i+1];
            vec[i] *= p;
        }
        
        return vec;
   
    }
    

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n, 0);
        
        vec[0] = 1;
        int p = 1;
        for (int i = 1; i < n; i++)
        {
            p = p * nums[i-1];
            vec[i] = p;
        }
        
        p = 1;
        for (int i = n-2; i >= 0; i--)
        {
            p = p * nums[i+1];
            vec[i] *= p;
        }
        
        return vec;
    }
    
    
    /* recursion */
    /* http://blog.csdn.net/wzy_1988/article/details/46916179 */
    
    public int[] productExceptSelfRev(int[] nums) {
        multiply(nums, 1, 0, nums.length);

        return nums;
    }

    private int multiply(int[] a, int fwdProduct, int indx, int N) {
        int revProduct = 1;
        if (indx < N) {
            revProduct = multiply(a, fwdProduct * a[indx], indx + 1, N);
            int cur = a[indx];
            a[indx] = fwdProduct * revProduct;
            revProduct *= cur;
        }
        return revProduct;
    }

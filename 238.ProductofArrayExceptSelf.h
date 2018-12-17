/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] 
is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].
https://leetcode.com/problems/product-of-array-except-self/
*/

/* 2018-10-22， 
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) return nums;
        
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> res(n, 0);
        
        left[0] = nums[0];
        for (int i = 1; i < n; i++) {
            left[i] = left[i-1] * nums[i];
        }
        
        right[n-1] = nums[n-1];
        for (int i = n-2; i > 0; i--) {
            right[i] = right[i+1] * nums[i];
        }
        
        res[0] = right[1];
        res[n-1] = left[n-2];
        
        for (int i = 1; i < n-1; i++) {
            res[i] = left[i-1] * right[i+1];
        }
        
        return res;
    }


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

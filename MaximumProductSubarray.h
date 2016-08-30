/*
 bluepp

 2014-11-22
 2014-11-27
 2014-12-01
 
 Problem:    Maximum Product Subarray
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/maximum-product-subarray/
 Notes:
 Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.
*/


/* 2016-08-31, update */

     int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        
        int minval = nums[0], maxval = nums[0];
        int ret = nums[0];
        
        for (int i = 1; i < n; i++)
        {
            int tval = maxval;
            
            maxval = max(max(maxval*nums[i], minval*nums[i]), nums[i]);
            minval = min(min(tval*nums[i], minval*nums[i]), nums[i]);
            
            ret = max(ret, maxval);
        }
        
        return ret;
    }

    int maxProduct_2(int A[], int n) {
        if(n==0) return 0;
        if(n==1) return A[0];
        int minVal = 0;
        int product = 1;
        int res = A[0];
        for(int i=0;i<n;i++){
            product = product*A[i];
            if(product<0){
                if(minVal==0) minVal=product;
                else {
                    res = max(res,product/minVal);
                    minVal=max(minVal,product);
                }
            }else if(product==0){
                res = max(res,product);
                product = 1;
                minVal=0;
            }else{
                res = max(res,product);
            }
        }
        return res;
    }

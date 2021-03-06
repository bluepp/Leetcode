/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity.
Could you implement it using only constant extra space complexity?
https://leetcode.com/problems/missing-number/
*/

/* 2016-08-29, update */

    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            x ^= (i+1) ^ nums[i];
        }
        
        return x;
    }


/* 2016-06-12, https://leetcode.com/discuss/106780/very-sample-java-solution */

    int missingNumber(vector<int>& nums) {
       
       int sum = 0;
       for (int i = 0; i < nums.size(); i++)
       {
           sum = sum-nums[i]+ i;
       }
       
       return sum + nums.size();
    }

/* 2016-06-12, xor, https://leetcode.com/discuss/103553/xor-java-solution */
public int missingNumber(int[] nums) {
    int missing = 0, i = 0;
    while(i < nums.length)
       missing ^= i ^ nums[i++]; 
    return missing ^ i;
}


    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++)
        {
            while (nums[i] != i)
            {
                if (nums[i] < 0 || nums[i] >= n) break;
                swap(nums[i], nums[nums[i]]);
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if (i != nums[i]) return i;
        }
        
        return n;
    }

/*
2016-06-16
bluepp
May the force be with me!

https://leetcode.com/problems/patching-array/

Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.

Example 1:
nums = [1, 3], n = 6
Return 1.

Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Example 2:
nums = [1, 5, 10], n = 20
Return 2.
The two patches can be [2, 4].

Example 3:
nums = [1, 2, 2], n = 5
Return 0.
Credits:
*/

/* 2017-02-09, update */
    int minPatches(vector<int>& nums, int n) {
        
        long miss = 1, res = 0, i = 0;
        
        while (miss <= n)
        {
            if (i < nums.size() && nums[i] <= miss)
            {
                miss += nums[i++];
            }
            else
            {
                miss += miss;
                res++;
            }
        }
        
        return res;
    }


/* https://leetcode.com/discuss/102653/c-8ms-greedy-solution-with-explanation */

int minPatches(vector<int>& nums, int n) {
    int cnt=0,i=0;
    long long maxNum=0;
    while (maxNum<n){
       if (i<nums.size() && nums[i]<=maxNum+1)
            maxNum+=nums[i++];
       else{
            maxNum+=maxNum+1;cnt++;
       }
   }
   return cnt;
}

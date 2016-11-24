/*
    bluepp
    
    2014-06-08
    2014-07-10
    2014-08-13
    2014-10-22
    2014-11-17
    
    May the force be with you!
    
    Problem:    First Missing Positive
    Source:     https://oj.leetcode.com/problems/first-missing-positive/
    Notes:
    Given an unsorted integer array, find the first missing positive integer.
    For example,
    Given [1,2,0] return 3,
    and [3,4,-1,1] return 2.
    Your algorithm should run in O(n) time and uses constant space.

    Solution: Although we can only use constant space, we can still exchange elements within input A!
           Swap elements in A and try to make all the elements in A satisfy: A[i] == i + 1.
           Pick out the first one that does not satisfy A[i] == i + 1.
 */
 
/* 2016-06-17, update */
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=0; i < n; i++)
        {
            while(nums[i]>= 1 && nums[i]<= n && nums[i]!=nums[nums[i]-1])
            {
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        int j=1;
        for(; j <= n; j++)
        {
            if (nums[j-1] != j)
            {
                break;
            }
        }

        return j;
      
    }

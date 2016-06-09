/*
bluepp
2016-06-09
May the force be with me!

https://leetcode.com/problems/wiggle-sort-ii/

Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

*/

/* 1. sort */
    void wiggleSort(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = (n%2 == 0) ? (n/2-1) : n/2;
        int index = 0;
        
        vector<int> tmp(n, 0);
        
        for (int i = 0; i <= mid; i++)
        {
            tmp[index] = nums[mid-i];
            
            if (index + 1 < n)
            {
                tmp[index+1] = nums[n-i-1];
            }
            
            index = index+2;
        }
        
        nums = tmp;
        
    }
    
    /* 2 https://leetcode.com/problems/wiggle-sort-ii/ */
    /* O(1),O(N) */
        void wiggleSort(vector<int>& nums) {
        
        int n = nums.size();
        
        auto midptr = nums.begin() + n/2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        #define A(i) nums[(1+2*(i)) % (n|1)]
        
        int i = 0, j = 0, k = n-1;
        while (j <= k)
        {
            if (A(j) > mid)
            {
                swap(A(i++), A(j++));
            }
            else if (A(j) < mid)
            {
                swap(A(j), A(k--));
            }
            else 
                j++;
            
        }
        
    }
    

/*
    bluepp
    May the force be with me!
    2014-06-20
    
   
 Problem:    Remove Duplicates from Sorted Array
 Source:     https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
 Notes:
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 Do not allocate extra space for another array, you must do this in place with constant memory.
 For example,
 Given input array A = [1,1,2],
 Your function should return length = 2, and A is now [1,2].

 Solution: Update 7/16/2013: Let j start from 0 for better understanding.
 */
    
     int removeDuplicates(int a[], int n) {
        if (n == 0 || n == 1)
            return n;
        
        int k = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[k] == a[i])
                continue;
            k++;    
            a[k] = a[i];
        }
        
        return k+1;
        
    }

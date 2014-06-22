/*
    bluepp
    2014-06-23
    May the force be with me!
    
   
 Problem:    Search in Rotated Sorted Array II
 Source:     https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 What if duplicates are allowed?
 Would this affect the run-time complexity? How and why?
 Write a function to determine if a given target is in the array.

 Solution: Sequence search. O(n)
           Since there are duplicates, it's hard to decide which branch to go if binary-search is deployed.
 */
 
    bool search(int a[], int n, int target) {
        
        for (int i = 0; i < n; i++)
        {
            if (a[i] == target)
                return true;    
        }
        
        return false;
    }

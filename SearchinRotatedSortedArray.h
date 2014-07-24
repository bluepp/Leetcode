/*
    bluepp
    2014-06-23
    2014-07-24
    May the force be with me!
    
    
 Problem:    Search in Rotated Sorted Array
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_33
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 You are given a target value to search. If found in the array return its index, otherwise return -1.
 You may assume no duplicate exists in the array.

 Solution: Binary search. O(lgn) eg. [4 5 6] -7- 8 1 2, 5 6 0 -1- [2 3 4]
 */
 
 
    int search(int a[], int n, int target) {
        int l = 0, r = n-1;
        while (l <= r)
        {
            int m = l + (r-l)/2;
            if (a[m] == target)
                return m;
                
            if (a[l] <= a[m])
            {
                if (target < a[m] && target >= a[l])
                    r = m-1;
                else
                    l = m+1;
            }
            else if (a[m] <= a[r])
            {
                if (target > a[m] && target <= a[r])
                    l = m+1;
                else
                    r = m-1;
            }
            else
                break;
            
        }
        
        return -1;
        
    }

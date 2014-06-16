/*
  bluepp
  2014-06-16
  May the force be with me!
  
  Problem:    Merge Sorted Array
  Source:     https://oj.leetcode.com/problems/merge-sorted-array/
  Notes:
  Given two sorted integer arrays A and B, merge B into A as one sorted array.
  Note:
  You may assume that A has enough space to hold additional elements from B. 
  The number of elements initialized in A and B are m and n respectively.

  Solution: From back to forth.
 */
 
    void merge(int a[], int m, int b[], int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while (i >= 0 && j >= 0)
        {
            if (a[i] >= b[j])
                a[k--] = a[i--];
            else
                a[k--] = b[j--];
        }
        
        while (j >= 0)
            a[k--] = b[j--];
        
    }

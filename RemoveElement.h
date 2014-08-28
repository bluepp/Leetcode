/*
    bluepp
    2014-06-20
    2014-07-22
    2014-08-28
    May the force be with me!

 Problem:    Remove Element
 Source:     https://oj.leetcode.com/problems/remove-element/
 Notes:
 Given an array and a value, remove all instances of that value in place and return the new length.
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.

 Solution: Refactor: Update solution. Use two pointers.
 */
 
    int removeElement(int A[], int n, int elem) {
        
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == elem) continue;
            A[k] = A[i];
            k++;
        }
        
        return k;
    }

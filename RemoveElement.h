/*
    bluepp
    2014-06-20
    May the force be with me!

 Problem:    Remove Element
 Source:     https://oj.leetcode.com/problems/remove-element/
 Notes:
 Given an array and a value, remove all instances of that value in place and return the new length.
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.

 Solution: Refactor: Update solution. Use two pointers.
 */
 
 int removeElement(int a[], int n, int elem) {
        
        if (n == 0)
            return 0;
        
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != elem && k < n)
            {
                a[k] = a[i];
                k++;
            }
            
        }
        
        return k;
        
    }

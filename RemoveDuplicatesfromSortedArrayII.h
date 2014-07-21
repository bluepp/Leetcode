/*
    bluepp
    2014-06-20
    2014-07-22
    May the force be with me!
    
    
 Problem:    Remove Duplicates from Sorted Array II
 Source:     https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 Notes:
 Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?
 For example,
 Given sorted array A = [1,1,1,2,2,3],
 Your function should return length = 5, and A is now [1,1,2,2,3].

 Solution: ...
 */
 
 
    int removeDuplicates(int a[], int n) {
        if (n == 0 || n == 1 || n == 2)
            return n;
        int k = 0, i = 0;
        
        while (i < n)
        {
            int first = i;
            a[k] = a[i];
            k++;
            
            while ((a[i] == a[i+1]) && (i < n))
            {
                i++;
            }
            int second = i;
            
            if (second != first)
            {   
                a[k] = a[second];
                k++;
            }
            
            i++;
         
        }
        
        return k;
     
    }
    
    ----------------------------
    
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int j = 2;
        for (int i = 2; i < n; ++i)
            if (A[i] != A[j-1] || A[i] != A[j-2])
                A[j++] = A[i];
        return j;
    }
    
    
    
    
    

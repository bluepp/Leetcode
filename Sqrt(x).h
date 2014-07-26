/*
    bluepp
    2014-06-26
    2014-07-27
    May the force be with me!
    
   
 Problem:    Sqrt(x)
 Source:     https://oj.leetcode.com/problems/sqrtx/
 Notes:
 Implement int sqrt(int x).
 Compute and return the square root of x.

 Solution: 1. Binary search in range [0, x / 2 + 1].
           2. Newton iteration method. x(i+1) = (x(i) + n/x(i)) / 2.
 See  (http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html) for more explanation (in Chinese).
 */
 
 
/* binary search */ 
    int sqrt(int x) {
        
        long long  l = 0, r = x/2+1;
        while (l <= r)
        {
            long long  m = l + (r-l)/2;
            long long  mm = m*m;
            
            if (mm == x)
                return m;
            else if (mm < x) l = m+1;
            else r = m-1;
        }
        
        return r;
    }
    
/* Newton Method */
???

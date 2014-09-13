/*
    bluepp
    
    2014-06-26
    2014-07-27
    2014-08-19
    2014-09-14
    
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
 
 
http://haixiaoyang.wordpress.com/?s=sqrt 
 
    int sqrt(int x) {
        
        unsigned long long nBeg = 0;
        unsigned long long nEnd = x;
        
        while (nBeg <= nEnd)
        {
            unsigned long long nMid = nBeg + (nEnd-nBeg)/2;
            if (nMid*nMid == x || (nMid*nMid < x && (nMid+1)*(nMid+1) > x))
                return nMid;
            else if (nMid*nMid < x)
                nBeg = nMid + 1;
            else nEnd = nMid-1;
        }
         
        return nBeg + (nEnd - nBeg)/2;
    } 
 
 
 
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

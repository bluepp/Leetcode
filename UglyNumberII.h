/*
  2015-08-19
  bluepp
  May the force be with me!
  
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note that 1 is typically treated as an ugly number.
https://leetcode.com/problems/ugly-number-ii/
*/

/* http://www.fgdsb.com/2015/01/03/ugly-numbers/ */
    int nthUglyNumber(int n) {
        unsigned i2 = 0, i3 = 0, i5 = 0;
        unsigned next_mul2 = 2, next_mul3 = 3, next_mul5 = 5;
        
        unsigned ret = 1;
        vector<unsigned> ugly(n);
        ugly[0] = 1;
        
        for (unsigned i = 1; i < n; i++)
        {
            ret = min(min(next_mul2, next_mul3), next_mul5);
            ugly[i] = ret;
            
            if (ret == next_mul2) next_mul2 = ugly[++i2]*2;
            if (ret == next_mul3) next_mul3 = ugly[++i3]*3;
            if (ret == next_mul5) next_mul5 = ugly[++i5]*5;
        }
        
        return ret;
    }

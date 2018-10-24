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


    int nthUglyNumber(int n) {
        
        vector<int> res(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        
        while (res.size() < n) {
            int m2 = res[i2] * 2, m3 = res[i3]*3, m5 = res[i5]*5;
            
            int mn = min(m2, min(m3, m5));
            if (mn == m2) i2++;
            if (mn == m3) i3++;
            if (mn == m5) i5++;
            
            res.push_back(mn);
        }
      
        int ret = res.back();
        return ret;
    }


/* http://www.fgdsb.com/2015/01/03/ugly-numbers/ */
   int nthUglyNumber(int n) {
        
        int i2 = 0, i3 = 0, i5 = 0;
        int next_mul2 = 2, next_mul3 = 3, next_mul5 = 5;
        
        int ret = 1;
        vector<int> ugly(n);
        ugly[0] = 1;
        
        for (int i = 1; i < n; i++)
        {
            ret = min(min(next_mul2, next_mul3), next_mul5);
            ugly[i] = ret;
            
            if (ret == next_mul2) next_mul2 = ugly[++i2]*2;
            if (ret == next_mul3) next_mul3 = ugly[++i3]*3;
            if (ret == next_mul5) next_mul5 = ugly[++i5]*5;
        }
        
        return ret;
    }


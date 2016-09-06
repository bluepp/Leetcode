/*
	bluepp
	
	2014-06-07
	2014-07-10
	2014-08-13
	2014-09-03
	2014-09-22
	2014-12-21
	2015-05-25
	
	May the force be with me!
	
 	Problem:    Divide Two Integers
  	Source:     https://oj.leetcode.com/problems/divide-two-integers/
 	Notes:
 	Divide two integers without using multiplication, division and mod operator.

 	Solution: Use << operator.
*/

/* 2016-09-06, update */

    int divide(int dividend, int divisor) {
        
        if (divisor == 0 || dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        
        long long m = abs((long long) dividend), n = abs((long long) divisor), res = 0;
        
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if (n == 1)
        {
            return sign == 1 ? m : -m;
        }
        
        while (m >= n)
        {
            long long t = n, p = 1;
            
            while (m >= (t << 1))
            {
                t <<= 1;
                p <<= 1;
            }
            
            res += p;
            m -= t;
        }
        
        return sign == 1 ? res : -res;
    }



    int divide(int dividend, int divisor) {
        
        long long dend = dividend, dsor = divisor;
        bool bneg = false;
        if (dend < 0)
        {
            bneg = !bneg;
            dend = -dend;
        }
        if (dsor < 0)
        {
            bneg = !bneg;
            dsor = -dsor;
        }
        
        long long ret = 0;
        while (dend >= dsor)
        {
            long long div = dsor;
            
            long long curr_q = 1;
            long long add = 1;
            while (dend >= div+div)
            {
                div <<= 1;
                curr_q <<= 1;
            }
            
            dend -= div;
            ret |= curr_q;
        }
        
        if (bneg) ret = -ret;
        if (ret > INT_MAX) return INT_MAX;
        return ret;
    }

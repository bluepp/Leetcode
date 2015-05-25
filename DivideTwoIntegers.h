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

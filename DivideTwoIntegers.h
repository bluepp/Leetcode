/*
	bluepp
	
	2014-06-07
	2014-07-10
	2014-08-13
	2014-09-03
	2014-09-22
	2014-12-21
	
	May the force be with me!
	
 	Problem:    Divide Two Integers
  	Source:     https://oj.leetcode.com/problems/divide-two-integers/
 	Notes:
 	Divide two integers without using multiplication, division and mod operator.

 	Solution: Use << operator.
*/

    int divide(int dividend, int divisor) {
       assert(divisor != 0);
       bool flag = ((divisor < 0 && dividend > 0) ||
            (divisor > 0 && dividend < 0));
       long long dend = abs((long long) dividend);
       long long dsor = abs((long long) divisor);
       int res = 0;
       
       while (dend >= dsor)
       {
           long long div = dsor;
           int curr_q = 1;
           
           while (dend >= div + div)
           {
               div <<= 1;
               curr_q <<= 1;
           }
           
           dend -= div;
           res |= curr_q;
       }
       
       return flag ? -res : res;
       
    }

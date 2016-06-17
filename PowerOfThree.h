/*
bluepp
2016-06-02
May the force be with me!

https://leetcode.com/problems/power-of-three/
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/

/* https://leetcode.com/discuss/78532/summary-all-solutions-new-method-included-at-15-30pm-jan-8th */

/* recursion */
    bool isPowerOfThree(int n) {
        
        return n>0 && (n==1 || (n%3==0 && isPowerOfThree(n/3)));
    }
    
/* iterative */
    bool isPowerOfThree(int n) {
        
        if (n > 1)
        {
            while(n % 3 == 0)
            {
                n /= 3;
            }
        }
        
        return n == 1;
    }


/* without any loop/recursion */
    bool isPowerOfThree(int n) {
        if (n<=0) return false;
        int t = pow(3,(int)(log(INT_MAX)/log(3)));
        return (t%n == 0);
    }

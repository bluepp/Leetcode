/*
    bluepp
    2014-06-19
    2014-07-20
    2014-08-27
    May the force be with me!
    
    Problem:    Pow(x, n)
    Source:     https://oj.leetcode.com/problems/powx-n/
    Notes:
    Implement pow(x, n).
 
    Solution: recursion.
 */
 
    double pow(double x, int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        bool neg = false;
        if (n < 0)
        {
            neg = true;
            n = -n;
        }
        
        double r = pow(x, n/2);
        double res = r * r;
        if (n % 2)
            res *= x;
        if (neg)
            res = 1 / res;
        
        return res;    
    }
    

/* 2016-09-06, update */    
    
        double myPow(double x, int n) {
        
        if (n == 0)
        {
            return 1;
        }
        
        if (n == 1)
        {
            return x;
        }
        
        double r = myPow(x, n/2);
        
        if (n % 2 == 0)
        {
            return r * r;
        }
        else if (n > 0)
        {
            return r * r * x;
        }
        else
        {
            return r*r/x;
        }
    }

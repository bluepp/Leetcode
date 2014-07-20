/*
    bluepp
    2014-06-19
    2014-07-20
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

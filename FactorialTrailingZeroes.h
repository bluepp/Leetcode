/*
2015-05-17
bluepp
May the force be with me!


Factorial Trailing Zeroes 
Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.

https://leetcode.com/problems/factorial-trailing-zeroes/

*/

/*http://www.fgdsb.com/2015/01/03/trailing-zeros/ */
int trailing_zeros(int n) {
    int ret = 0;
    for(int i = 5; n / i >= 1; i *= 5)
        ret += n / i;
    return ret;
}

/* linear */
    int trailingZeroes(int n) {
        if (n < 0) return -1;
        int count = 0;
        
        while (n > 0)
        {
            n /= 5;
            count += n;
        }
        
        return count;
    }

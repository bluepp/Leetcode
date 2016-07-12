/*
  2015-06-08
  bluepp
  May the force be with me!
  
  https://leetcode.com/problems/bitwise-and-of-numbers-range/
  Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/

/* https://leetcode.com/discuss/98124/java-7-ms-solution */
/*
For example, If the first 10 bits of binary representation of m is 01110011 00, 
while the first 10 of n is 01110011 01, there must be a number,
which is lager than m and smaller than n, 
have a binary representation with the 10th bit is 1 and following 22 bit are all 0(same to negative numbers). 
As all number between m and n are all start with 01110011 0, the result of bitwise AND is 01110011 0 + 23(0)
*/

/* 2016-07-12, update */
  int rangeBitwiseAnd(int m, int n) {
        
        int i = 0;
        while (m != n)
        {
            m >>= 1;
            n >>= 1;
            i++;
        }
        
        return m << i;
        
    }


    int rangeBitwiseAnd(int m, int n) {
        
        int i = 0;
        for (; i < 32; i++)
        {
            if (m >> i == n >> i)
            {
                break;
            }
        }
        
        return m >> i << i;
    }




/* http://math.stackexchange.com/questions/1073532/how-to-find-bitwise-and-of-all-numbers-for-a-given-range */
    int rangeBitwiseAnd(int m, int n) {
    
       int x = 0;
       while ((m | x) < n)
       {
           x = (x << 1) | 1;
       }
       
       return m & ~x;
    }
  

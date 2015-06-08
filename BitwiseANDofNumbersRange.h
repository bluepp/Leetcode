/*
  2015-06-08
  bluepp
  May the force be with me!
  
  https://leetcode.com/problems/bitwise-and-of-numbers-range/
  Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/

/* http://math.stackexchange.com/questions/1073532/how-to-find-bitwise-and-of-all-numbers-for-a-given-range */
    int rangeBitwiseAnd(int m, int n) {
    
       int x = 0;
       while ((m | x) < n)
       {
           x = (x << 1) | 1;
       }
       
       return m & ~x;
    }
  

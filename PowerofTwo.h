/*
  2015-07-06
  bluepp
  May the force be with me!
  
  Given an integer, write a function to determine if it is a power of two.
  
  https://leetcode.com/problems/power-of-two/
*/

   bool isPowerOfTwo(int n) {
        
        return (n > 0) && !(n & (n-1));
    }


/* 2016-06-17, update */
    bool isPowerOfTwo(int n) {
        if (n < 0) return false;
        
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            int bit = 1 << i;
            if (bit & n)
            {
                count ++;
            }
        }
        
        return count == 1;
    }

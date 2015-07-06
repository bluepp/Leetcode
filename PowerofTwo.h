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

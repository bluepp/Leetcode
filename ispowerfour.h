/*
  2016-06-01
  bluepp
  May the force be with me!
  
  https://leetcode.com/problems/power-of-four/
  
  Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?

Credits:
Special thanks to @yukuairoy for adding this problem and creating all test cases.
*/

    bool isPowerOfFour(int num) {
        if ((num & (num -1)) != 0) return false;
        if (num & 0x55555555) return true;
        return false;
    }

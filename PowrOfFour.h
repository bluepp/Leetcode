/* 
bluepp
2016-06-17
May the force be with me!

https://leetcode.com/problems/power-of-four/

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
*/

/*
https://leetcode.com/discuss/97930/java-1-line-cheating-for-the-purpose-of-not-using-loops

Good solution without good explanation,
it's easy to find that power of 4 numbers have those 3 common features.First,greater than 0.
Second,only have one '1' bit in their binary notation,so we use x&(x-1) to delete the lowest '1',
and if then it becomes 0,it prove that there is only one '1' bit.
Third,the only '1' bit should be locate at the odd location,for example,16.I
t's binary is 00010000.So we can use '0x55555555' to check if the '1' bit is in the right place.
With this thought we can code it out easily!
*/

    bool isPowerOfFour(int num) {
      
      return (nums > 0 ) && (num&(num-1)) == 0 && (num & 0x55555555) != 0;  
      
    }
    
    bool isPowerOfFour(int num) {
      
      return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0; 
      
    }



/* 
  2015-09-04
  bluepp
  May the force be with me!
  
Count 1 in Binary Show result 
Count how many 1 in binary representation of a 32-bit integer.

Have you met this question in a real interview? Yes
Example
Given 32, return 1
Given 5, return 2
Given 1023, return 9

Challenge
If the integer is n bits with m 1 bits. Can you do it in O(m) time?
http://www.lintcode.com/en/problem/count-1-in-binary/#
*/
    int countOnes(int num) {
        // write your code here
        int count = 0;
        for(; num > 0; num &= num-1){
            count++;
        }
        return count;
        
    }


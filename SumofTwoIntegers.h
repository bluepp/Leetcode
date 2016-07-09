/* 
bluepp
2016-07-10
May the force be with me!

https://leetcode.com/problems/sum-of-two-integers/

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
*/

   int getSum(int a, int b) {
        
        if (b == 0)
        {
            return a;
        }
        
        int sum = a ^ b;
        int carry = (a & b) << 1;
        
        return getSum(sum, carry);
    }

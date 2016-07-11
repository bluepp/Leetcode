/*
bluepp
2016-07-12
May the force be with me!

https://leetcode.com/problems/valid-perfect-square/

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False

*/

    bool isPerfectSquare(int num) {
        
        for (int i = 1; i <= num/i; i++)
        {
            if (i*i == num)
            {
                return true;
            }
        }
        
        return false;
    }
    
    
     bool isPerfectSquare(int num) {
        long left = 0, right = num;
        while (left <= right) {
            long mid = left + (right - left) / 2, t = mid * mid;
            if (t == num) return true;
            else if (t < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }

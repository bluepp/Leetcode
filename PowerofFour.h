/*
bluepp
2017-01-12
May the force be with me!

https://leetcode.com/problems/power-of-four/

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?

Credits:
Special thanks to @yukuairoy for adding this problem and creating all test cases.
*/


/* logab = logcb / logca, ==> log3n = log10n / log103*/

    bool isPowerOfFour(int num) {
        
        return (num > 0 && int(log10(num) / log10(4)) - log10(num) / log10(4) == 0);
        
    }

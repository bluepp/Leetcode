/*
bluepp
2016-06-02
May the force be with me!

https://leetcode.com/problems/power-of-three/
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/

    bool isPowerOfThree(int n) {
        if (n<=0) return false;
        int t = pow(3,(int)(log(INT_MAX)/log(3)));
        return (t%n == 0);
    }

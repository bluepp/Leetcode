/*
    bluepp
    2014-06-24
    2014-07-26
    2014-08-20
    May the force be with me!
    
   
 Problem:    Single Number
 Source:     http://oj.leetcode.com/problems/single-number/
 Notes:
 Given an array of integers, every element appears twice except for one. 
 Find that single one.
 Your algorithm should have a linear runtime complexity. 
 Could you implement it without using extra memory?

 Solution: XOR.
*/

    int singleNumber(int a[], int n) {
        int x = 0;
        
        for (int i = 0; i < n; i++)
            x ^= a[i];
        
        return x;   
    
    }

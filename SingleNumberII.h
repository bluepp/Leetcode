/*
    bluepp
    2014-06-24
    May the force be with me!
    
    
 Problem:    Single Number II
 Source:     http://oj.leetcode.com/problems/single-number-ii/
 Notes:
 Given an array of integers, every element appears three times except for one. 
 Find that single one.
 Your algorithm should have a linear runtime complexity. Could you implement it 
 without using extra memory?

 Solution: Count the number of each bit.
*/

    int singleNumber(int a[], int n) {
        int x = 0;
        
        for (int i = 0; i < 32; i++)
        {
            int count = 0, bit = 1 << i;
            for (int j = 0; j < n; j++)
            {
                if (a[j] & bit)
                    count ++;
            }
            
            if (count % 3 != 0)
                x |= bit;
            
        }
        
        return x;
        
    }

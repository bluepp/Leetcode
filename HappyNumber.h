/*
  2015-06-15
  bluepp
  May the force be with me!
  
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by
the sum of the squares of its digits, and repeat the process
until the number equals 1 (where it will stay), or it loops
endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

https://leetcode.com/problems/happy-number/
*/

    bool isHappy(int n) {
        
        int sum = 0;
        
        if (n == 1) return true;
        
        while (n)
        {
            sum += (n%10) * (n%10);
            n /= 10;
        }
        
        if (sum == 1) return true;
        else if (sum > 9) return isHappy(sum);
        else return false;
    }
    
    
    bool isHappy(int n) {
        
        int sum = 0;
        
        while (1)
        {
            if (n == 1) return true;
            
            while (n)
            {
                sum += (n%10) * (n%10);
                n /= 10;
            }
            
            if (sum == 1) return true;
            else if (sum < 10) return false;
            else 
            {
                n = sum;
                sum = 0;
            }
        }
    }

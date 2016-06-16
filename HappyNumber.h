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

/* https://leetcode.com/discuss/101005/4-c-solutions-with-explanations */

    bool isHappy(int n) {
        
        unordered_set<int> tmp;

        while(n != 1)
        {
            if(tmp.find(n) == tmp.end())
                tmp.insert(n);
            else
                return false;

            int sum = 0;
            while(n != 0)
            {
                sum += pow(n % 10, 2);
                n = n / 10;
            }

            n = sum;
        }

        return true;
    }

/*
  2015-08-16
  bluepp
  May the force be with me!
  
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

https://leetcode.com/problems/add-digits/
*/


/* 2016-06-30, another one */
   int addDigits(int num) {
        
        return (num - 1) % 9 + 1;
      
    }


/* no recursion, no loop, https://leetcode.com/discuss/52160/one-line-solution */
    int addDigits(int num) {
        return num%9 == 0? (num==0?0:9) : num % 9;
    }


/* recursion */
    int addDigits(int num) {
        
        if (num < 10)
        {
            return num;
        }
        
        int ret = 0;
        while (num)
        {
            ret += num % 10;
            num /= 10;
        }
        
        return addDigits(ret);
    }

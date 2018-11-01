/*
    bluepp
    
    2014-06-21
    2014-07-23
    2014-09-02
    2014-11-23
    
    May the force be with me!
    
    
 Problem:    Reverse Integer
 Source:     https://oj.leetcode.com/problems/reverse-integer/
 Notes:
 Reverse digits of an integer.
 Example1: x = 123, return 321
 Example2: x = -123, return -321

 Have you thought about this?
 Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
 If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
 Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).

 Solution: Use % and / iteratively.
 */


    int reverse(int x) {
        long long ret = 0;
        
        while (x) {
            ret = ret *10 + (x%10);
            x /= 10;
        }
        
        if (ret > INT_MAX || ret < INT_MIN) {
            return 0;
        } else {
            return ret;
        }

    }


 
 /*
    2014-11-23
    To check for overflow/underflow, we could check if ret > 214748364 or ret < –214748364 before multiplying by 10. 
    On the other hand, we do not need to check if ret == 214748364, why?
 */
 
    int reverse(int x) {
        
        int ret = 0;
        while (x != 0) {
        // handle overflow/underflow
            if (abs(ret) > 214748364) {
                return 0;
            }
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        
        return ret;
    }
 
 
 
 
    int reverse(int x) {
        
        long long num = 0;
        while(x)
        {
            num = num * 10 + x % 10;
            x /= 10;
        }
        
        return num;    
        
    }

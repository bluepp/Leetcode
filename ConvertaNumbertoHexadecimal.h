/*
2016-10-12
bluepp
May the force be with me!

https://leetcode.com/problems/convert-a-number-to-hexadecimal/

Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"
*/

    string toHex(int num) {
        
        string res = "";
        
        for (int i = 0; num && i < 8; i++)
        {
            int t = num & 0xf;
            
            if (t >= 10)
            {
                res = char('a' + t -10) + res;
            }
            else
            {
                res = char('0'+t) + res;
            }
            
            num >>= 4;
        }
        
        return res.empty() ? "0" : res;
    }

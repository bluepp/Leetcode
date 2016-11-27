/*
bluepp
2013-11-23
May the force be with me!

https://leetcode.com/problems/add-strings/

Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

    string addStrings(string num1, string num2) {
        
        string res = "";
        int m = num1.size(), n = num2.size();
        int i = m-1, j = n-1, carry = 0;
        
        while (i >= 0 || j >= 0)
        {
            int sum = carry;
            
            if (i >= 0)
            {
                sum += num1[i]-'0';
                i--;
            }
            
            if (j >= 0)
            {
                sum += num2[j]-'0';
                j--;
            }
            
            res.insert(res.begin(), sum%10 +'0');
            carry = sum/10;
        }
        
        return carry ? "1"+res : res;
    }

/*
    bluepp
    2014-06-17
    May the force be with me!
    
    Problem:    Multiply Strings
    Source:     https://oj.leetcode.com/problems/multiply-strings/
    Notes:
    Given two numbers represented as strings, return multiplication of the numbers as a string.
    Note: The numbers can be arbitrarily large and are non-negative.

    Solution: Just like what we do when multiplying integers.
 */
 
 
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        string res(m+n, '0');
        
        for (int i= n-1; i >= 0; i--)
        {
            int carry = 0;
            
            for (int j = m-1; j >=0; j--)
            {
                int sum = carry + res[i+j+1]-'0'
                    + (num1[i] - '0') * (num2[i] - '0');
                res[i+j+1] = sum % 10 + '0';
                carry = sum / 10;
            }
            
            res[i] += carry;
        }
        
        while (res.size() > 1 && res[0] == '0')
            res.erase(res.begin());
        
        return res;    
    }

/*
    bluepp
    
    2014-06-17
    2014-07-17
    2014-09-13
    2014-10-26
    
    May the force be with me!
    
    Problem:    Multiply Strings
    Source:     https://oj.leetcode.com/problems/multiply-strings/
    Notes:
    Given two numbers represented as strings, return multiplication of the numbers as a string.
    Note: The numbers can be arbitrarily large and are non-negative.

    Solution: Just like what we do when multiplying integers.
 */
 
 
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        string res(n1+n2, '0');
        
        for (int i = n1-1; i >= 0; i--)
        {
            int carry = 0;
            for (int j = n2-1; j >= 0; j--)
            {
                int t = (num1[i]-'0')*(num2[j]-'0')+(res[i+j+1]-'0')+carry;
                
                int num = t % 10;
                carry = t/10;
                res[i+j+1] = num+'0';
            }
            
            res[i] += carry;
        }
        
        while(res.size() > 1 && res[0] == '0')
            res.erase(res.begin());
        
        return res;   
    }

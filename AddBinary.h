/*
 bluepp
 May the force be with me.
 
 2014-05-28
 2014-07-06
 2014-08-03
 2014-09-14

 Problem:    Add Binary
 Source:     https://oj.leetcode.com/problems/add-binary/
 Notes:
 Given two binary strings, return their sum (also a binary string).
 For example,
 a = "11"
 b = "1"
 Return "100".

 Solution: '1'-'0' = 1.
 */
 
  string addBinary(string a, string b) {
        int m = a.size(), n = b.size(), K = max(m, n);
        string res(K, ' ');
        int carry = 0;
        int i = m-1, j = n-1, k = K-1;
        
        while (i >= 0 || j >= 0)
        {
            int sum = carry;
            if (i >= 0) 
            {
                sum += a[i] - '0';
                i--;
            }
            
            if (j >= 0) 
            {
                sum += b[j] - '0';
                j--;
            }
            
            carry = sum / 2;
            res[k] = sum % 2 + '0';
            k--;
        }
        
        if (carry == 1)
            res.insert(res.begin(), '1');
            
        return res;
    }
       

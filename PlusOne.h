/*
    bluepp
    
    2014-06-19
    2014-07-19
    2014-09-03
    
    May the force be with me!
 
    Problem:    Plus One
    Source:     http://leetcode.com/onlinejudge#question_66https://oj.leetcode.com/problems/plus-one/
    Given a number represented as an array of digits, plus one to the number.

    Solution: ...
 */
 
    vector<int> plusOne(vector<int> &digits) {
       int carry = 1;
       
       for (int i = digits.size() -1 ; i >= 0 && carry; i--)
       {
           int sum = digits[i] + carry;
           digits[i] = sum % 10;
           carry = sum / 10;
       }
       
       if (carry)
            digits.insert(digits.begin(), 1);
        
       return digits;    
       
    }

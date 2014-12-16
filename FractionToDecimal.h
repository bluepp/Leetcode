/*
  bluepp
  2014-12-17
  May the force be with me!
  
https://oj.leetcode.com/problems/fraction-to-recurring-decimal/
Fraction to Recurring Decimal Total Accepted: 51 Total Submissions: 487 My Submissions Question Solution 
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/

    string fractionToDecimal(int numerator, int denominator) {

        long long num = numerator, den = denominator;
    
        bool bneg = false;
        if (num < 0)
        {
            bneg = !bneg;
            num = -num;
        }
        if (den < 0)
        {
            bneg = !bneg;
            den = -den;
        }

        string ret = to_string(num / den);
        num %= den;
    
        if (num != 0) ret.push_back('.');
    
        map<int,int> rems;
   
        while(num != 0 && !rems.count(num)) {
            rems[num] = (int)ret.size();
            num *= 10;
            ret += to_string(num/den);
            num %= den;
        }
   
   
        if (num != 0) {
            ret.insert(ret.begin() + rems[num], '(');
            ret += ")";
        } 
    
        if (bneg && !(ret.size() == 1 && ret[0] == '0'))
        {
            ret.insert(ret.begin(), '-');
        }
    
        return ret;
    }

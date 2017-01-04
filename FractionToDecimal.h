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
        
        int s1 = numerator >= 0 ? 1 : -1;
        int s2 = denominator >= 0 ? 1 : -1;
        
        long long num = abs( (long long)numerator );
        long long den = abs( (long long)denominator );
        long long out = num / den;
        long long rem = num % den;
        
        unordered_map<long long, int> map;
        string res = to_string(out);
        
        if (s1 * s2 == -1 && (out > 0 || rem > 0)) res = "-" + res;
        if (rem == 0) return res;
        
        res += ".";
        string s = "";
        int pos = 0;
        
        while (rem != 0) {
            
            if (map.count(rem))
            {
                s.insert(map[rem], "(");
                s += ")";
                return res+s;
            }
            
            map[rem] = pos;
            s += to_string((rem * 10) / den);
            rem = (rem * 10) % den;
            pos++;
        }
        
        return res + s;
    }

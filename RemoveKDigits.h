/*
bluepp
2016-11-07
May the force be with me!

https://leetcode.com/problems/remove-k-digits/

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

    string removeKdigits(string num, int k) {
        
        string res = "";
        int n = num.size(), keep = n-k;
        
        for(char c : num)
        {
            while (k && res.size() && res.back() > c)
            {
                res.pop_back();
                k--;
            }
            
            res.push_back(c);
        }
        
        res.resize(keep);
        
        while (!res.empty() && res[0] == '0')
        {
            res.erase(res.begin());
        }
        
        return res.empty() ? "0" : res;
        
    }

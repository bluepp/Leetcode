/*
bluepp
2016-11-23
May the force be with me!

https://leetcode.com/problems/repeated-substring-pattern/

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

*/
    bool repeatedSubstringPattern(string str) {
        
        int n = str.length();
        
        for (int i = n/2; i >= 1; i--)
        {
            if (n%i == 0)
            {
                int c = n/i;
                string t = "";
                
                for (int j = 0; j < c; j++)
                {
                    t += str.substr(0, i);
                }
                
                if (t == str) return true;
            }
        }
        
        return false;
    }

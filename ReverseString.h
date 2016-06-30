/*
2016-06-30
bluepp
May the force be with me!

https://leetcode.com/problems/reverse-string/

Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

    string reverseString(string s) {
        
        int l = 0, r = s.length()-1;
        
        while (l < r)
        {
            swap(s[l++], s[r--]);
        }
        
        return s;
    }

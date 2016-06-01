/*
2016-06-01
bluepp
May the force be with me!

https://leetcode.com/problems/reverse-string/

Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

*/

    string reverseString(string s) {
        if (s.empty()) return s;
        reverse(s.begin(), s.end());
        
        return s;
    }

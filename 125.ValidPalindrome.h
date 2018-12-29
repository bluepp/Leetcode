/*
  bluepp
  
  2014-07-01
  2014-07-30
  2014-08-16
  2014-09-21
  
  May the force be with me!
  
  
 Problem:    Valid Palindrome
 Source:     https://oj.leetcode.com/problems/valid-palindrome/
 Notes:
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 For example,
 "A man, a plan, a canal: Panama" is a palindrome.
 "race a car" is not a palindrome.
 Note:
 Have you consider that the string might be empty? This is a good question to ask during an interview.
 For the purpose of this problem, we define empty string as valid palindrome.

 Solution: traverse from both side.
 */

#include <cctype> 

    bool isPalindrome(string s) {
        int n = s.size();
        if (n == 0) return true;
        
        int l = 0, r = n-1;

        while (l < r)
        {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;
            
            if (tolower(s[l]) != tolower(s[r])) return false;
            l++; r--;
        }
        
        return true;
    }

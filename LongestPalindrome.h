/*
2016-10-13
bluepp
May the force be with me!

https://leetcode.com/problems/longest-palindrome/

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

    int longestPalindrome(string s) {
        
        int ret = 0;
        bool mid = false;
        unordered_map<char, int> map;
        
        for (auto p : s)
        {
            map[p]++;
        }
        
        for (auto it : map)
        {
            ret += it.second;
            if (it.second % 2)
            {
                ret -= 1;
                mid = true;
            }
        }
        
        return mid ? ret +1 : ret;
        
    }

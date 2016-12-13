/*
bluepp
2016-12-14
May the force be with me!

https://leetcode.com/problems/number-of-segments-in-a-string/

Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5

*/

   int countSegments(string s) {
        int res = 0, n = s.size();
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') continue;
            ++res;
            while (i < n && s[i] != ' ') ++i;
        }
        
        return res;
        
    }

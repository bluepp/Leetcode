/*
  bluepp
  2014-12-20
  May the force be with me!

https://github.com/bluepp/Leetcode/new/master  
Excel Sheet Column Title Total Accepted: 23 Total Submissions: 198 My Submissions Question Solution 
Given a non-zero positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/   

/* recursion */
    string convertToTitle(int n) {
        if (n == 0) return "";
        int r = (n-1)%26;
        char c = r+'A';
        return convertToTitle((n-r)/26)+c;
    }
    
/* iterative */    
     string convertToTitle(int n) {
        string result = "";
        while (n) {
            result += (--n % 26) + 'A';
            n /= 26;
        }
        return string(result.rbegin(), result.rend());
    }

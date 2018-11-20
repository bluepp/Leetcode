/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

*/

    bool validPalindrome(string s) {
        int l = 0, r = s.length()-1;
        while (l < r){
            if (s[l] != s[r]) {
                return _isPal(s, l, r-1) || _isPal(s, l+1, r);
            }
            
            l++;
            r--;
        }
        
        return true;
    }
    
    bool _isPal(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            
            l++;
            r--;
        }
        
        return true;
    }

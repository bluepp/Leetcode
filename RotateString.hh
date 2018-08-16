/*
We are given two strings, A and B.

A shift on A consists of taking string A and moving the leftmost character to the rightmost position. For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. Return True if and only if A can become B after some number of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false
Note:

A and B will have length at most 100.
*/
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) return false;
      
        int n = A.size();
        if (n == 0) return true;
        
        for (int i = 0; i < n; i++) {
            string s1 = A;
            if (i >= 1) {
                s1 = A.substr(i) + A.substr(0, i);
            }
            
            if (s1 == B) return true;
        }
        
        return false;        
    }

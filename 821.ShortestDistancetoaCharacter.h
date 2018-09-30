/*
Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
*/

    vector<int> shortestToChar(string S, char C) {
        
        int n = S.length();
   
        vector<int> res(n, INT_MAX);
    
        int index = -1;
    
        for (int i = 0; i < n; ++i) {
            if (S[i] == C) index = i;
            if (index < 0) continue;
            res[i] = abs(i - index);
        }
        
        index = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (S[i] == C) index = i;
            if (index < 0) continue;
            res[i] = min(res[i], abs(i - index));
        }
        
        return res;
    }

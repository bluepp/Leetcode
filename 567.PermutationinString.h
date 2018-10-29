/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        unordered_map<char, int> map, m2;
        
        for (auto p : s1) {
            map[p]++;
        }
        
        for (int i = 0; i < n2-n1+1; i++) {
            
            bool success = true;
            m2 = map;
            
            for (int j = i; j < i+n1; j++) {
                if (--m2[s2[j]] < 0) {
                    success = false;                   
                }
            }
            
            if (success) {
                return true;
            }
        }
        
        return false;
    }

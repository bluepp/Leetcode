/*
 bluepp
 
 2014-10-24
 2014-12-19
 
 May the force be with me!
 
 
 Problem:    Longest Palindromic Substring
  Source:    https://oj.leetcode.com/problems/longest-palindromic-substring/
 Notes:
 Given a string S, find the longest palindromic substring in S. 
 You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

 Solution: 1. Time O(n^2), Space O(n^2)
           2. Time O(n^2), Space O(n)
           3. Time O(n^2), Space O(1) (actually much more efficient than 1 & 2)
           4. Time O(n), Space O(n) (Manacher's Algorithm)
 */
 
 
 /* solutioin 3 */
    string longestPalindrome(string s) {
        int n = s.size();
        pair<int, int> res(make_pair(0, 0));
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                bool isP = true;

                for (int k = 0; i-k >= 0 && i+j+k < n && isP; k++)
                {
                    isP = s[i-k] == s[i+j+k];
                    
                    if (isP && j+1+k*2 > res.second)
                        res = make_pair(i-k, j+1+k*2);
                }
            }
        }
        
        return s.substr(res.first, res.second);
    }

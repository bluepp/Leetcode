/*
    bluepp  
    
    2014-06-07
    2014-07-10
    2014-08-13
    2014-09-03
    2014-09-09
    
    May the force be with me!
    
    Problem:    Decode Ways
    Source:     https://oj.leetcode.com/problems/decode-ways/
    Notes:
    A message containing letters from A-Z is being encoded to numbers using the following mapping:
    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26
    Given an encoded message containing digits, determine the total number of ways to decode it.
    For example,
    Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
    The number of ways decoding "12" is 2.

    Solution: dp. Note that '0' must be decoded in together with the number in front of it.
*/

    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[n] = 1;
        dp[n-1] = s[n-1] == '0' ? 0 : 1;
        
        for (int i = n-2; i >= 0; i--)
        {
            char c0 = s[i], c1 = s[i+1];
            if (c0 == '0')
            {
                dp[i] = 0;
                continue;
            }
            
            dp[i] = dp[i+1];
            if (c0 == '1' || (c0 =='2' && c1 <= '6'))
                dp[i] += dp[i+2];
        }
        
        return dp[0];
    }

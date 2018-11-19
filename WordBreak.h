/*
    bluepp
    
    2014-07-02
    2014-07-30
    2014-08-16
    2014-09-20
    2014-11-23
    
    May the force be with me!
    
 Problem:    Word Break
 Source:     http://oj.leetcode.com/problems/word-break/
 Notes:
 Given a string s and a dictionary of words dict, determine if s can be segmented into 
 a space-separated sequence of one or more dictionary words.
 For example, given
 s = "leetcode",
 dict = ["leet", "code"].
 Return true because "leetcode" can be segmented as "leet code".

 Solution: dp.
*/


/* memo */

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return _check(s, wordSet, 0, memo);
    }
    
    bool _check(string s, unordered_set<string> &wordSet, int start, vector<int>& memo) {
        if (start >= s.size()) {
            return true;
        }
        
        if (memo[start] != -1) {
            return memo[start];
        }
        
        for (int i = start+1; i <= s.length(); i++) {
            if (wordSet.count(s.substr(start, i-start)) && _check(s, wordSet, i, memo)) {
                return memo[start] = 1;
            }
        }
        
        return memo[start] = 0;
    }


    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        bool dp[n+1];
        memset(dp, false, sizeof(dp));
        dp[n] = true;
        
        for (int i = n; i >= 0; i--)
        {
            for (int j = i+1; j <= n ; j ++)
            {
                if (dp[j] && dict.find(s.substr(i, j-i)) != dict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        
        return dp[0];
        
    }

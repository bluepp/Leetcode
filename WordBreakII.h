/*
    bluepp
    2014-07-02
    May the force be with me!
    
 Problem:    Word Break II
 Source:     http://oj.leetcode.com/problems/word-break-ii/
 Notes:
 Given a string s and a dictionary of words dict, add spaces in s to 
 construct a sentence where each word is a valid dictionary word.
 Return all such possible sentences.
 For example, given
 s = "catsanddog",
 dict = ["cat", "cats", "and", "sand", "dog"].
 A solution is ["cats and dog", "cat sand dog"].

 Solution: check before constructing the sentences.
*/

vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        if (!_possible(s, dict)) return res;
        _break(s, dict, 0, "", res);
             
        return res;
    }
    
    void _break(string s, unordered_set<string> &dict, int start, string ss, vector<string> &res)
    {
        if (start == s.size())
        {
            res.push_back(ss);
            return;
        }
        
        if (start != 0) ss.push_back(' ');
        
        for (int i = start; i < s.size(); i++)
        {
            string tmp = s.substr(start, i-start+1);
            if (dict.find(tmp) == dict.end()) continue;
           
            _break(s, dict, i+1, ss+tmp, res);
           
        }
    }
    
    bool _possible(string s, unordered_set<string> &dict)
    {
        int n = s.size();
        bool dp[n+1];
        memset(dp, false, sizeof(dp));
        dp[n] = true;
        
        for (int i = n-1; i >= 0; i--)
        {
            for (int j = i+1; j <= n; j++)
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
    

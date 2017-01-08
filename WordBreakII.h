/*
    bluepp
    
    2014-07-02
    2014-07-30
    2014-08-16
    2014-09-21
    2014-11-14
    2014-12-06
    2014-12-30
    
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

/* 2017-01-08, update */
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        vector<string> res;
        string out;
        vector<bool> possible(s.size() + 1, true);
        
        unordered_set<string> set;
        for (auto str : wordDict)
        {
            set.insert(str);
        }
        
        wordBreakDFS(s, set, 0, possible, out, res);
        return res;
    }
    
    void wordBreakDFS(string s, unordered_set<string> &wordDict, int start, vector<bool> &possible, string &out, vector<string> &res) {
        if (start == s.size()) {
            res.push_back(out.substr(0, out.size() - 1));
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            string word = s.substr(start, i - start + 1);
            if (wordDict.find(word) != wordDict.end() && possible[i + 1]) {
                out.append(word).append(" ");
                int oldSize = res.size();
                wordBreakDFS(s, wordDict, i + 1, possible, out, res);
                if (res.size() == oldSize) possible[i + 1] = false;
                out.resize(out.size() - word.size() - 1);
            }
        }
    }


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




/* 2017-01-08, uodate, TLE ? */
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        vector<string> res;
        if (wordDict.empty() || wordDict[0].empty()) return res;
        
        unordered_map<string, int> map;
        for (auto str : wordDict)
        {
            map[str]++;
        }
        
        _dfs(s, map, 0, "", res);
        return res;
    }
    
    void _dfs(string s, unordered_map<string, int> map, int start, string str, vector<string> &res)
    {
        if (start == s.length())
        {
            res.push_back(str);
            return;
        }
        
        if (!str.empty()) str += ' ';
        
        for (int i = start; i < s.length(); i++)
        {
            string t = s.substr(start, i-start+1);
            
            if (map.count(t))
            {
                _dfs(s, map, i+1, str+t, res);
            }
        }
    }
    

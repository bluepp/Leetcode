/*
    bluepp
    2014-06-17
    2014-07-19
    2014-08-23
    May the force be with me!

    Problem:    Palindrome Partitioning
    Source:     https://oj.leetcode.com/problems/palindrome-partitioning/
    Notes:
    Given a string s, partition s such that every substring of the partition is a palindrome.
    Return all possible palindrome partitioning of s.
    For example, given s = "aab",
    Return
    [
        ["aa","b"],
        ["a","a","b"]
    ]

    Solution: ...
 */
 

/* 2017-03-08, update */

    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;
        vector<string> vec;
        
        _dfs(s, 0, vec, res);
        return res;
    }
    
    void _dfs(string s, int start, vector<string> &vec, vector<vector<string>> &res)
    {
        if (start == s.length())
        {
            res.push_back(vec);
            return;
        }
        
        for (int i = start; i < s.length(); i++)
        {
            string t = s.substr(start, i-start+1);
            if (!isvalid(t)) continue;
            
            vec.push_back(t);
            _dfs(s, i+1, vec, res);
            vec.pop_back();
        }
    }
    
    bool isvalid(string s)
    {
        int l = 0, r = s.length()-1;
        
        while (l < r)
        {
            if (s[l++] != s[r--]) return false;
        }
        
        return true;
    }
 

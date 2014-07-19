/*
    bluepp
    2014-06-17
    2014-07-19
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
 
 bool isPal(string s)
    {
        int n = s.size();
        int start = 0, end = n-1;
        while (start <= end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
           
             start ++;
             end --;
          
        }
        
        return true;
     
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> vec;
        vector<vector<string> > res;
        int n = s.size();
        
        _pal(s, 0, n, vec, res);
        
        return res;
    }
    
    void _pal(string s, int start, int end, vector<string> & vec, vector<vector<string> > &res)
    {
        if (start >= end)
        {
            res.push_back(vec);
            return;
        }
        
        string tmp;
        
        for (int i = start; i < end; i++)
        {
            tmp.push_back(s[i]);
            if (!isPal(tmp))
            {
                continue;
            }
            vec.push_back(tmp);
            _pal(s, i+1, end, vec, res);
            vec.pop_back();
        }
     
    }
 

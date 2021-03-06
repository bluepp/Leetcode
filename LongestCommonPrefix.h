/*
    bluepp
    
    2014-06-12
    2014-07-15
    2014-08-26
    2014-09-05
    
    May the force be with me!
    
    Problem:    Longest Common Prefix
    Source:     https://oj.leetcode.com/problems/longest-common-prefix/
    Notes:
    Write a function to find the longest common prefix string amongst an array of strings.

    Solution: ...
 */
 
 /* 2016-08-28, update */
    string longestCommonPrefix(vector<string>& strs) {
        
        string res;
        if (strs.empty())
        {
            return res;
        }
        
        for (int j = 0; j < strs[0].length(); j++)
        {
            int i = 1;
            for (; i < strs.size(); i++)
            {
                if (strs[i][j] != strs[0][j])
                {
                    return res;
                }
            }
            
            res.push_back(strs[0][j]);
        }
        
        return res;
       
    }
 
    string longestCommonPrefix(vector<string> &strs) {
       string res;
       if (strs.empty()) return res;
       
       int n = strs[0].size(), m = strs.size();
       
       for (int j = 0; j < n; j++)
       {
           char tmp = strs[0][j];
           
           for (int i = 1; i < m; i++)
           {
               if (tmp != strs[i][j]) return res;
           }
           
           res.push_back(tmp);
       }
       
       return res;
       
    }

/*
    bluepp
    2014-06-12
    May the force be with me!
    
    Problem:    Longest Common Prefix
    Source:     https://oj.leetcode.com/problems/longest-common-prefix/
    Notes:
    Write a function to find the longest common prefix string amongst an array of strings.

    Solution: ...
 */
 
    string longestCommonPrefix(vector<string> &strs) {
        string res;
        if (strs.empty())
            return res;
        
        
        for (int j = 0; j < strs[0].size(); j++)
        {
            char t = strs[0][j];
            
            for (int i = 0; i < strs.size(); i++)
            {
                if (j == strs[i].size() || strs[i][j] != t)
                    return res;
            }
            
            res.push_back(t);
           
        }
        
        return res;
   
    }

/*
    bluepp
    
    2014-06-26
    2014-08-19
    2014-11-03
    2014-11-20
    
    May the force be with me!
    
    
 Problem:    Subsets II
 Source:     https://oj.leetcode.com/problems/subsets-ii/
 Notes:
 Given a collection of integers that might contain duplicates, S, return all possible subsets.
 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If S = [1,2,2], a solution is:
 [
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
 ]

 Solution: ..Similar to Subset I, except for line 45.
 */
 
 vector<vector<int> > subsetsWithDup(vector<int> &s) {
        vector<vector<int> > res(1, vector<int>());
        vector<int> vec;
        sort(s.begin(), s.end());
        
        for (int i = 1; i <= s.size(); i++)
        {
            _subset(s, 0, i, vec, res);
        }
        
        return res;
    }
    
    void _subset(vector<int> &s, int start, int length, vector<int>& vec, vector<vector<int> > &res)
    {
        int n = s.size(), m = vec.size();
        if (m == length)
        {
            res.push_back(vec);
            return;
        }
        
        for (int i= start; i <= n - (length - m); i++)
        {
            if (i > start && s[i] == s[i-1]) continue;
            vec.push_back(s[i]);
            _subset(s, i+1, length, vec, res);
            vec.pop_back();
         
        }
    }

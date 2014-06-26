/*
    bluepp
    2014-06-26
    May the force be with me!
    
   
 Problem:    Subsets
 Source:     https://oj.leetcode.com/problems/subsets/
 Notes:
 Given a set of distinct integers, S, return all possible subsets.
 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If S = [1,2,3], a solution is:
 [
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
 ]

 Solution: 1. Recursive solution.
           2. Iterative solution. 
 */


/* recursion solution , DFS*/

    vector<vector<int> > subsets(vector<int> &s) {
        vector<vector<int> > res(1, vector<int>());
        vector<int> vec;
        sort(s.begin(), s.end());
        
        for (int i = 1; i <= s.size(); i++)
        {
            _subset(s, 0, i, vec, res);
        }
        
        return res;
     
    }
    
    void _subset(vector<int> &s, int start, int length, vector<int> &vec, vector<vector<int>> &res)
    {
        int n = s.size(), m = vec.size();
        if (length == m)
        {
            res.push_back(vec);
            return;
        }
        
        for (int i = start; i <= n - (length - m); i++)
        {
            vec.push_back(s[i]);
            _subset(s, i+1, length, vec, res);
            vec.pop_back();
        }
        
    }    
    
    
    

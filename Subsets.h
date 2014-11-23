/*
    bluepp
    
    2014-06-26
    2014-07-27
    2014-08-19
    2014-11-16
    2014-11-23
    
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


/* 2014-11-23, my version */

    vector<vector<int> > subsets(vector<int> &s) {
        vector<int> vec;
        vector<vector<int> > res;
        
        int n = s.size();
        sort(s.begin(), s.end());
        
        for (int i = 0; i <= n; i++)
        {
            _sub(s, 0, i, vec, res);
        }
        
        return res;
    }
    
    
    void _sub(vector<int> &s, int start, int len, vector<int>& vec, vector<vector<int> >&res)
    {
        if (vec.size() == len)
        {
            res.push_back(vec);
            return;
        }
        
        for (int i = start; i < s.size(); i++)
        {
            vec.push_back(s[i]);
            _sub(s, i+1, len, vec, res);
            vec.pop_back();
        }
    }
 
 
 

/* 2014-11-16 , my version */
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
        
        for (int i = start; i < n; i++)
        {
            vec.push_back(s[i]);
            _subset(s, i+1, length, vec, res);
            vec.pop_back();
        }
        
    }    


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
    
    
    

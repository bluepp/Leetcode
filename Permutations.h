/*
	bluepp	
	2014-06-19
	May the force be with me!
	
	
 	Problem:    Permutations
 	Source:	 https://oj.leetcode.com/problems/permutations/     
 	Notes:
 	Given a collection of numbers, return all possible permutations.
 	For example,
 	[1,2,3] have the following permutations:
 	[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

 	Solution: dfs...
 */
 
 	vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        vector<bool> avail(num.size(), true);
        vector<int> pum;
        
        _perm(num, avail, pum, res);
        
        return res;
    }
    
    void _perm(vector<int> &num, vector<bool> &avail, vector<int> &pum, vector<vector<int> > &res)
    {
        if (pum.size() == num.size())
        {
            res.push_back(pum);
            return;
        }
        
        for (int i = 0; i < num.size(); i ++)
        {
            if (avail[i])
            {
                avail[i] = false;
                pum.push_back(num[i]);
                _perm(num, avail, pum, res);
                pum.pop_back();
                avail[i] = true;
                
            }
        }
    }

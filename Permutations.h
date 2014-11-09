/*
	bluepp	
	
	2014-06-19
	2014-07-19
	2014-11-05
	2014-11-09
	
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
        vector<int> vec;
        vector<vector<int> >res;
        vector<bool> avail(num.size(), true);
        
        _perm(num, avail, vec, res);
        return res;
    }
    
    void _perm(vector<int> &num, vector<bool> &avail, vector<int>&vec, vector<vector<int> >&res)
    {
        if(vec.size() == num.size())
        {
            res.push_back(vec);
            return;
        }
        
        for (int i = 0; i < num.size(); i++)
        {
            if (avail[i])
            {
                avail[i] = false;
                vec.push_back(num[i]);
                _perm(num, avail, vec, res);
                vec.pop_back();
                avail[i] = true;
            }
        }
    }

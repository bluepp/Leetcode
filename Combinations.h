/*
	bluepp
	2014-06-05
	2014-07-08
	2014-08-12
	May the force be with me!
	
	Problem:    Combinations
  	Source:     https://oj.leetcode.com/problems/combinations/
 	Notes:
 	Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 	For example,
 	If n = 4 and k = 2, a solution is:
 		[
    		[2,4],
    		[3,4],
    		[2,3],
    		[1,2],
    		[1,3],
    		[1,4],
 	]

 	Solution: DFS.
 */
 
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> vec;
        _comb(1, n, k, vec, res);
        return res;
        
    }
    
    void _comb(int start, int n, int k, vector<int>&vec, vector<vector<int> >&res)
    {
        int t = vec.size();
        if (t == k)
        {
            res.push_back(vec);
            return;
        }
        
        for (int i = start; i <= (n - (k-t) + 1); i++)
        {
            vec.push_back(i);
            _comb(i+1, n, k, vec, res);
            vec.pop_back();
        }
    }

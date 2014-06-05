/*
	bluepp
	2014-06-05
	May the force be with me!
	
	Problem:    Combination Sum
  	Source:     https://oj.leetcode.com/problems/combination-sum/
 	Notes:
 	Given a set of candidate numbers (C) and a target number (T), find all unique 
 	combinations in C where the candidate numbers sums to T.
 	The same repeated number may be chosen from C unlimited number of times.
 	Note:
 	All numbers (including target) will be positive integers.
 	Elements in a combination (a1, a2, .. , ak) must be in non-descending order. (ie, a1 <= a2 <= ... <= ak).
 	The solution set must not contain duplicate combinations.
 	For example, given candidate set 2,3,6,7 and target 7, 
 	A solution set is: 
 		[7] 
 		[2, 2, 3] 

 	Solution: Sort & Recursion.
*/

	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        vector<int> vec;
        _comb(candidates, target, 0, vec, res);
        
        return res;
    }
    
    void _comb(vector<int> &candidates, int target, int start, vector<int>&vec, vector<vector<int> > &res)
    {
        if (target == 0)
        {
            res.push_back(vec);
            return;
        }
        
        for (int i = start; i < candidates.size() && target >= candidates[i]; i++)
        {
            vec.push_back(candidates[i]);
            _comb(candidates, target-candidates[i], i, vec, res);
            vec.pop_back();
        }
            
    }

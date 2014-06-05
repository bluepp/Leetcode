/*
	bluepp
	2014-06-05
	May the force be with me!
	
	Problem:    Combination Sum II
 	Source:     https://oj.leetcode.com/problems/combination-sum-ii/
 
 	Notes:
 	Given a collection of candidate numbers (C) and a target number (T), find all unique combinations
 	in C where the candidate numbers sums to T.
 	Each number in C may only be used once in the combination.
 	Note:
 	All numbers (including target) will be positive integers.
 	Elements in a combination (a1, a2, .. , ak) must be in non-descending order. (ie, a1 <= a2 <= ... <= ak).
 	The solution set must not contain duplicate combinations.
 	For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 	A solution set is: 
 		[1, 7] 
 		[1, 2, 5] 
 		[2, 6] 
 		[1, 1, 6] 

 	Solution: ..Similar to Combination Sum I, except for line 42 && 44.
*/

	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> >res;
        vector<int> vec;
        
        sort(num.begin(), num.end());
        _comb(num, 0, target, vec, res);
        return res;
    }
    
    void _comb(vector<int>& num, int start, int target, vector<int>& vec, vector<vector<int> >& res)
    {
        if (target == 0)
        {
            res.push_back(vec);
            return;
        }
        
        for(int i = start; i < num.size() && target >= num[i]; i++)
        {
            if (i > start && num[i] == num[i-1]) continue;
            vec.push_back(num[i]);
            _comb(num, i+1, target-num[i], vec, res);
            vec.pop_back();
        }
    }

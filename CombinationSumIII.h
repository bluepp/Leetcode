/*
  bluepp
  2015-06-10
  May the force be with me!
  
  Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]

https://leetcode.com/problems/combination-sum-iii/
*/

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vec;
        vector<vector<int> > res;
        
        _comb(k, 1, n, vec, res);
        return res;
    }
    
    void _comb(int k, int start, int n, vector<int> vec, vector<vector<int> > &res)
    {
        if (vec.size() == k && n == 0)
        {
            res.push_back(vec);
            return;
        }
        
        if (vec.size() == k || n == 0) return;
        
        for (int i = start; i <= 9; i++)
        {
            vec.push_back(i);
            _comb(k, i+1, n-i, vec, res);
            vec.pop_back();
        }
    }




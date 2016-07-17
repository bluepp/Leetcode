/*
  2015-08-12
  bluepp
  May the force be with me!
  
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note: 
Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2].
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Examples: 
input: 1
output: 
[]
input: 37
output: 
[]
input: 12
output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]

https://leetcode.com/problems/factor-combinations/

*/

/* 2016-07-18, update */

    vector<vector<int>> getFactors(int n) {
        
        vector<int> vec;
        vector<vector<int>> res;
        
        _factor(n, 2, vec, res);
        return res;
    }
    
    void _factor(int n, int start, vector<int> vec, vector<vector<int>>& res)
    {
        if (n == 1)
        {
            if (vec.size() > 1)
            {
                res.push_back(vec);
                return;
            }
        }
        
        for (int i = start; i <= n; i++)
        {
            if (n % i == 0)
            {
                vec.push_back(i);
                _factor(n/i, i, vec, res);
                vec.pop_back();
            }
        }
    }


/* https://leetcode.com/discuss/51257/share-simple-c-dfs-accepted-solution */
    vector<vector<int>> getFactors(int n) {
        vector<int> vec;
        vector<vector<int> > res;
        
        if (n == 1) return res;
        
        _factor(n, vec, res);
        return res;
    }
    
    void _factor(int n, vector<int> vec, vector<vector<int> > &res)
    {
        int i = vec.empty() ? 2 : vec.back();
        
        for (; i <= n/i; i++)
        {
            if (n % i == 0)
            {
                vec.push_back(i);
                vec.push_back(n/i);
                res.push_back(vec);
                vec.pop_back();
                
                _factor(n/i, vec, res);
                vec.pop_back();
            }
        }
    }



/*
  2015-08-28
  bluepp
  May the force be with me!
  
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement,
where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

https://leetcode.com/problems/n-queens/
*/

/* bit map */
    vector<vector<string>> solveNQueens(int n) {
        vector<string> vec;
        vector<vector<string>> res;
        
        _sol(n, 0, 0, 0, vec, res);
        return res;
    }
    
    void _sol(int n, int row, int ld, int rd, vector<string> vec, vector<vector<string> >&res)
    {
        if (row == (1<< n)-1)
        {
            res.push_back(vec);
            return;
        }
        
        int avail = ~(row|ld|rd);
        for (int i = 0; i < n; i++)
        {
            int pos = 1 << i;
            
            if (avail & pos)
            {
                string s (n, '.');
                s[i] = 'Q';
                
                vec.push_back(s);
                _sol(n, row|pos, (ld|pos) << 1, (rd|pos) >> 1, vec, res);
                vec.pop_back();
            }
        }
    }

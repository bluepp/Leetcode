/*
    bluepp
    
    2014-06-28
    2014-12-07
    
    May the force be with me!
    
    
 Problem:    Surrounded Regions
 Source:     https://oj.leetcode.com/problems/surrounded-regions/
 Notes:
 Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 A region is captured by flipping all 'O's into 'X's in that surrounded region .
 For example,
 X X X X
 X O O X
 X X O X
 X O X X
 After running your function, the board should be:
 X X X X
 X X X X
 X X X X
 X O X X

 Solution: Traverse from the boarder to the inside and mark all the 'O's that are not surrounded by 'X' as 'V' (visited).
           1. DFS.
           2. BFS (queue).
 */
 

/* 2017-01-18, my version, fail to pass large data */
    void solve(vector<vector<char>>& board) {
        
        if (board.empty() || board[0].empty()) return;
        
        int m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0 || i == m-1 || j == n-1)
                {
                    _dfs(board, i, j);
                }
            }
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != 'X')
                {
                    board[i][j] = (board[i][j] == 'T') ? 'O' : 'X';
                }
            }
        }
     
    }
    
    
    void _dfs(vector<vector<char>> &board, int i, int j)
    {
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') return;
        
        board[i][j] = 'T';        
        
        _dfs(board, i+1, j);
        _dfs(board, i-1, j);
        _dfs(board, i, j+1);
        _dfs(board, i, j-1);
        
    }

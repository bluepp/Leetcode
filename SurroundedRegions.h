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
 
 void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty()) return;
        
        int m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0 || i == m-1 || j == n-1)
                    _dfs(board, i, j);
            }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != 'V')
                {
                    board[i][j] = (board[i][j] == 'V') ? 'O' : 'X';
                }
            }
        }
    }
    
   
    void _dfs(vector<vector<char> >&board, int row, int col)
    {
        int m = board.size(), n = board[0].size();
        if (row < 0 || row >= n || col < 0 || col >= m) return;
        
        if (board[row][col] != 'O') return;
        
        board[row][col] = 'V';
        
        _dfs(board, row+1, col);
        _dfs(board, row-1, col);
        _dfs(board, row, col+1, m, n);
        _dfs(board, row, col-1, m, n);
        
    }

/*
bluepp
2017-02-24
May the force be with me!

https://leetcode.com/problems/sudoku-solver/?tab=Description

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


*/
    void solveSudoku(vector<vector<char>>& board) {
        
        if (board.empty() || board.size() != 9 || board[0].size() != 9) return;
        
        _dfs(board, 0, 0);
    }
    
    bool _dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i == 9) return true;
        if (j >= 9) return _dfs(board, i+1, 0);
        
        if (board[i][j] == '.')
        {
            for (int k = 1; k <= 9; k++)
            {
                board[i][j] = (char)(k+'0');
                
                if (isvalid(board, i, j))
                {
                    if (_dfs(board, i, j+1)) return true;
                }
                
                board[i][j] = '.';
            }
        }
        else
        {
            return _dfs(board, i, j+1);
        }
        
        return false;
    }
    
    bool isvalid(vector<vector<char>> &board, int i, int j)
    {
        for (int col = 0; col < 9; col++)
        {
            if (col != j && board[i][j] == board[i][col]) return false;
        }
        
        for (int row = 0; row < 9; row++)
        {
            if (row != i && board[i][j] == board[row][j]) return false;
        }
        
        for (int row = i/3*3; row < i/3*3+3; row++)
        {
            for (int col = j/3*3; col < j/3*3 +3; col++)
            {
                if ((row != i || col != j) && (board[i][j] == board[row][col]))
                {
                    return false;
                }
            }
        }
        
        return true;
    }

/* 
  2015-11-14
  bluepp
  May the force be with me!
  
According to the Wikipedia's article: "The Game of Life, also known simply as Life, 
is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). 
Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the
following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

https://leetcode.com/problems/game-of-life/
*/

/* 2016-06-10 update */
/* https://leetcode.com/discuss/68352/easiest-java-solution-with-explanation */

    void gameOfLife(vector<vector<int>>& board) {
        
        if (board.empty() || board[0].empty()) return ;
        int m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int live = _live(board, m, n, i, j);
                
                if (board[i][j] == 1 && live >= 2 && live <= 3)
                {
                    board[i][j] = 3;
                }
                if (board[i][j] == 0 && live == 3)
                {
                    board[i][j] = 2;
                }
            }
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] >>= 1;
            }
        }
    }
    
    
    int _live(vector<vector<int>> &board, int m, int n, int i, int j)
    {
        int live = 0;
        
        for (int x = max(i-1, 0); x <= min(i+1, m-1); x++)
        {
            for (int y = max(j-1, 0); y <= min(j+1, n-1); y++)
            {
                live += board[x][y] & 1;
            }
        }
        
        live -= board[i][j] & 1;
        
        return live;
    }




/* https://leetcode.com/discuss/64111/c-o-mn-time-o-1-space-sol*/
/* o(mn) */

    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty()) return;
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                check(board,i,j,i+1,j-1);
                check(board,i,j,i+1,j);
                check(board,i,j,i+1,j+1);
                check(board,i,j,i,j+1);
                
                if(board[i][j]>=5 && board[i][j]<=7) board[i][j]=1;
                else board[i][j]=0;
            }
        }
    }
    
    void check(vector<vector<int>>& board, int i, int j, int a, int b) 
    {
        const int m = board.size();
        const int n = board[0].size();
        if(a >= m || b<0 || b >= n) return;
        
        if(board[i][j]%2!=0) board[a][b] += 2;
        if(board[a][b]%2!=0) board[i][j] += 2;
    } 

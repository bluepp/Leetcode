/*
Let's play the minesweeper game (Wikipedia, online game)!

You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

If a mine ('M') is revealed, then the game is over - change it to 'X'.
If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.
 

Example 1:

Input: 

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]

Output: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:

Example 2:

Input: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Click : [1,2]

Output: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:

 

Note:

The range of the input matrix's height and width is [1,50].
The click position will only be an unrevealed square ('M' or 'E'), which also means the input board contains at least one clickable square.
The input board won't be a stage when game is over (some mines have been revealed).
For simplicity, not mentioned rules should be ignored in this problem. For example, you don't need to reveal all the unrevealed mines when the game is over, consider any cases that you will win the game or flag any squares.
*/


    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click){
        
        if (board.empty() || board[0].empty()){
            return {};
        }
        
        int m = board.size(), n = board[0].size();
        int row = click[0], col = click[1];
        int count = 0;
      
        if (board[row][col] == 'M'){
            board[row][col] = 'X';
        } else {
            
            vector<vector<int>> neighbors;
            
            for (int i = -1; i < 2; i++){
                for (int j = -1; j < 2; j++){
                    int x = row+i, y = col+j;
                    
                    if (x < 0 || x >= m || y < 0 || y >= n){
                        continue;
                    }
                    
                    if (board[x][y] == 'M'){
                        count++;
                    } else if (count == 0 && board[x][y] == 'E'){
                        neighbors.push_back({x, y});
                    }
                }
            }
            
            if (count > 0){
                board[row][col] = count+'0';
            } else {
                for (auto p : neighbors){
                    board[p[0]][p[1]] = 'B';
                    updateBoard(board, p);
                }
            }
        }
      
        return board;
    }



/* wrong... */
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click){
        
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        if (click.size() < 2){
            return board;
        }
        int i = click[0], j = click[1];
        
        _dfs(board, i, j, visited);
        
        return board;
    }
    
    bool _dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited){
        
        int m = board.size(), n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j]){
            return false;
        }
        
        visited[i][j] = true;
        
        if (board[i][j] == 'M'){
            board[i][j] = 'X';
            return true;
        }
        
        int dirs[] = {{1, 0}, {1, -1},{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}};
        
        if (board[i][j] == 'E'){
            int count = 0;
            
            for (int k = 0; k < 8; j++){
                int x = i + dirs[k][0], y = j + dirs[k][1];
                
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]){
                    continue;
                }
                
                visited[x][y] = true;
                
                if (_dfs(board, x, y, visited)){
                    count++;
                }
            }
            
            if (count == 0){
                board[i][j] = 'B';
            } else {
                board[i][j] = itoa(count);
            }
        }
        
        return false;

    }

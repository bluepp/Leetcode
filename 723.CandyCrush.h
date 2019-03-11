/*
This question is about implementing a basic elimination algorithm for Candy Crush.

Given a 2D integer array board representing the grid of candy, different positive integers board[i][j] represent different types of candies. A value of board[i][j] = 0 represents that the cell at position (i, j) is empty. The given board represents the state of the game following the player's move. Now, you need to restore the board to a stable state by crushing candies according to the following rules:

If three or more candies of the same type are adjacent vertically or horizontally, "crush" them all at the same time - these positions become empty.
After crushing all candies simultaneously, if an empty space on the board has candies on top of itself, then these candies will drop until they hit a candy or bottom at the same time. (No new candies will drop outside the top boundary.)
After the above steps, there may exist more candies that can be crushed. If so, you need to repeat the above steps.
If there does not exist more candies that can be crushed (ie. the board is stable), then return the current board.
You need to perform the above rules until the board becomes stable, then return the current board.

 

Example:

Input:
board = 
[[110,5,112,113,114],[210,211,5,213,214],[310,311,3,313,314],[410,411,412,5,414],[5,1,512,3,3],[610,4,1,613,614],[710,1,2,713,714],[810,1,2,1,1],[1,1,2,2,2],[4,1,4,4,1014]]

Output:
[[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[110,0,0,0,114],[210,0,0,0,214],[310,0,0,113,314],[410,0,0,213,414],[610,211,112,313,614],[710,311,412,613,714],[810,411,512,713,1014]]

Explanation: 

 

Note:

The length of board will be in the range [3, 50].
The length of board[i] will be in the range [3, 50].
Each board[i][j] will initially start as an integer in the range [1, 2000].
*/

    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        while (true) {
            vector<pair<int, int>> del;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (board[i][j] == 0) continue;
                    int x0 = i, x1 = i, y0 = j, y1 = j;
                    while (x0 >= 0 && x0 > i - 3 && board[x0][j] == board[i][j]) --x0;
                    while (x1 < m && x1 < i + 3 && board[x1][j] == board[i][j]) ++x1;
                    while (y0 >= 0 && y0 > j - 3 && board[i][y0] == board[i][j]) --y0;
                    while (y1 < n && y1 < j + 3 && board[i][y1] == board[i][j]) ++y1;
                    if (x1 - x0 > 3 || y1 - y0 > 3) del.push_back({i, j});
                }
            }
            if (del.empty()) break;
            for (auto a : del) board[a.first][a.second] = 0;
            for (int j = 0; j < n; ++j) {
                int t = m - 1;
                for (int i = m - 1; i >= 0; --i) {
                    if (board[i][j]) swap(board[t--][j], board[i][j]);   
                }
            }
        }
        
        return board;
        
    }

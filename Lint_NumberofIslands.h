/*
  2015-09-08
  bluepp
  May the force be with me!
 
 
Given a boolean 2D matrix, find the number of islands.

Have you met this question in a real interview? Yes
Example
Given graph:

[
  [1, 1, 0, 0, 0],
  [0, 1, 0, 0, 1],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 0, 0],
  [0, 0, 0, 0, 1]
]
return 3.

Note
0 is represented as the sea, 1 is represented as the island.
If two 1 is adjacent, we consider them in the same island.
We only consider up/down/left/right adjacent.

http://www.lintcode.com/en/problem/number-of-islands/#
*/

    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j]) _dfs(grid, i, j, count++);
            }
        }
        
        return count;
    }
    
    void _dfs(vector<vector<bool> > &grid, int row, int col, int count)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return;
        if (!grid[row][col]) return;
        
        grid[row][col] = false;
        _dfs(grid, row+1, col, count);
        _dfs(grid, row-1, col, count);
        _dfs(grid, row, col+1, count);
        _dfs(grid, row, col-1, count);
        
    }

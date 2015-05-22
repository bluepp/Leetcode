/* 2015-05-22
  bluepp
  May the force be with me!
  
  Number of Islands Total Accepted: 8342 Total Submissions: 38329 My Submissions Question Solution 
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

https://leetcode.com/problems/number-of-islands/
*/
   int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        
        int count = 2;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    _island(grid, i, j, count++);
                }
            }
        }
        
        return count-2;
    }
    
    void _island(vector<vector<char> >&grid, int row, int col, int count)
    {
        int m = grid.size(), n = grid[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n) return;
        
        if (grid[row][col] != '1') return;
        grid[row][col] = count+'0';
        
        _island(grid, row+1, col, count);
        _island(grid, row-1, col, count);
        _island(grid, row, col+1, count);
        _island(grid, row, col-1, count);
    }


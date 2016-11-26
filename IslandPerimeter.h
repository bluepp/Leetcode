/*
2016-11-26
bluepp
May the force be with me!

https://leetcode.com/problems/island-perimeter/

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:

*/

    int islandPerimeter(vector<vector<int>>& grid) {
        
        if (grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.empty(), n = grid[0].empty();
        int ret = 0;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0) continue;
                
                if (j == 0 || grid[i][j-1] == 0) ret ++;
                if (i == 0 || grid[i-1][j] == 0) ret++;
                if (j = n-1 || grid[i][j+1] == 0) ret++;
                if (i = m-1 || grid[i+1][j] == 0) ret++;
            }
        }
        
        return ret;
        
    }

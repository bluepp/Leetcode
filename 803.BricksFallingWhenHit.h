/*
We have a grid of 1s and 0s; the 1s in a cell represent bricks.  A brick will not drop if and only if it is directly connected to the top of the grid, or at least one of its (4-way) adjacent bricks will not drop.

We will do some erasures sequentially. Each time we want to do the erasure at the location (i, j), the brick (if it exists) on that location will disappear, and then some other bricks may drop because of that erasure.

Return an array representing the number of bricks that will drop after each erasure in sequence.

Example 1:
Input: 
grid = [[1,0,0,0],[1,1,1,0]]
hits = [[1,0]]
Output: [2]
Explanation: 
If we erase the brick at (1, 0), the brick at (1, 1) and (1, 2) will drop. So we should return 2.
Example 2:
Input: 
grid = [[1,0,0,0],[1,1,0,0]]
hits = [[1,1],[1,0]]
Output: [0,0]
Explanation: 
When we erase the brick at (1, 0), the brick at (1, 1) has already disappeared due to the last move. So each erasure will cause no bricks dropping.  Note that the erased brick (1, 0) will not be counted as a dropped brick.
 

Note:

The number of rows and columns in the grid will be in the range [1, 200].
The number of erasures will not exceed the area of the grid.
It is guaranteed that each erasure will be different from any other erasure, and located inside the grid.
An erasure may refer to a location with no brick - if it does, no bricks drop.
*/



/* runtime error */
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        
        vector<int> res;
        if (grid.empty() || grid[0].empty()){
            return res;
        }
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        
        for (int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                if (grid[0][j] && grid[i][j]){
                    dp[i][j] = true;
                } else {
                    break;
                }
            }
        }
       
        /*
        for (auto hit : hits){
            int count = _dfs(grid, hit.first, hit.second, dp);
            res.pusht _back(count);
        }
        */
        
        for (int i = 0; i < hits.size(); i++){
            for (int j = 0; j < hits.size(); j++){
                int count = _dfs(grid, i, j, dp);
                res.push_back(count);
            }
        }
        
        return res;
    }
    
    
    vector<vector<int>> dirs = {{1, 0}, {0, -1}, {0, 1}};
    int _dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &dp){
        
        if (!dp[i][j]){
            return 0;
        }
        
        int m = grid.size(), n = grid[0].size();
        
        grid[i][j] = 0;
        dp[i][j] = false;
        
        int count = 1;
        for (int k = 0; k < 3; k++){
            int x = i + dirs[k][0], y = j + dirs[k][1];
            
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0){
                continue;
            }
            
            dp[i][j] = false;
            grid[i][j] = 0;
            
            count += _dfs(grid, x, y, dp);
        }
        
        return count;
    }

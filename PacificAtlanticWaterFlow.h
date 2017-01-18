/*
bluepp
2016-11-05
May the force be with me!

https://leetcode.com/problems/pacific-atlantic-water-flow/

Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).

*/

/* dfs */

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        if (matrix.empty() || matrix[0].empty()) return {};
        vector<pair<int, int>> res;
        int m = matrix.size(), n = matrix[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++)
        {
            _dfs(matrix, pacific, INT_MIN, i, 0);
            _dfs(matrix, atlantic, INT_MIN, i, n-1);
        }
        
        for (int i = 0; i < n; i++)
        {
            _dfs(matrix, pacific, INT_MIN, 0, i);
            _dfs(matrix, atlantic, INT_MIN, m-1, i);
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }
        
        return res;
    }
    
    void _dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int pre, int i, int j)
    {
        int m = matrix.size(), n = matrix[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || matrix[i][j] < pre)
        {
            return;
        }
        
        visited[i][j] = true;
        
        _dfs(matrix, visited, matrix[i][j], i+1, j);
        _dfs(matrix, visited, matrix[i][j], i-1, j);
        _dfs(matrix, visited, matrix[i][j], i, j+1);
        _dfs(matrix, visited, matrix[i][j], i, j-1);
    }
    


/* 2017-01-18, runtime error */

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        vector<pair<int, int>> res;
        int m = matrix.size(), n = matrix[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
       
        
        for(int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (_upleft(matrix, i, j, INT_MAX)) pacific[i][j] = true;
                if (_downright(matrix, i, j, INT_MAX)) atlantic[i][j] = true;
                
            }
        }
        
        
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    res.push_back({i,j});
                }
            }
        }
        
        
        return res;
    }
    
    
    bool _upleft(vector<vector<int>> &matrix, int i, int j, int pre)
    {
        
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()|| matrix[i][j] >= pre) return false;
        
        if (i == 0 || j == 0) return true;
        
        if (_upleft(matrix, i-1, j, matrix[i][j]) || _upleft(matrix, i, j-1, matrix[i][j]))
        {
            return true;
        }
        
        
        return false;
    }
    
    bool _downright(vector<vector<int>> &matrix, int i, int j, int pre)
    {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix.size() || matrix[i][j] >= pre) return false;
        
        if (i == matrix.size()-1 || j == matrix[0].size()-1) return true;
        
        if (_downright(matrix, i+1, j, matrix[i][j]) || _downright(matrix, i, j+1, matrix[i][j]))
        {
            return true;
        }
        
        return false;
    }
    

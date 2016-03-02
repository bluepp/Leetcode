/* bluepp
  2016-02-29
  May the force be with me!
  
  Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

     int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        if(matrix.size() == 0) return 0;
        int Max = 0;
        vector<int> tem(matrix[0].size(),0);
        vector<vector<int>> hash(matrix.size(), tem);
        for(int i = 0; i< matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                Max = max(DFS(matrix, i, j, INT_MIN, hash), Max);
        return Max;
    }
    
    int DFS(vector<vector<int>>& matrix, int y, int x, int val, vector<vector<int>>& hash)
    {
        if(y < 0 || y >= matrix.size() || x <0 || x >= matrix[0].size())
            return 0;
        if(matrix[y][x] > val)
        {
            if(hash[y][x] != 0) return hash[y][x]; //if this path has been searched
            int a = DFS(matrix, y, x+1,matrix[y][x], hash) + 1;
            int b = DFS(matrix, y, x-1,matrix[y][x], hash) + 1;
            int c = DFS(matrix, y+1, x,matrix[y][x], hash) + 1;
            int d = DFS(matrix, y-1, x,matrix[y][x], hash) + 1;
            hash[y][x] = max(a, max(b,max(c, d)));
            return hash[y][x];
        }
        return 0;
    }


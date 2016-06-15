/*
bluepp
2016-06-02
May the force be with me!
ou are given a m x n 2D grid initialized with these three possible values.
-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
Show Company Tags
Show Tags
Show Similar Problems
*/

/* BFS */
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> que;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i = 0; i < rooms.size(); i++){
            for(int j = 0; j < rooms[0].size(); j++){
                if(rooms[i][j] == 0) que.push({i, j});
            }
        }
        while(!que.empty()){
            int x = que.front().first, y = que.front().second;
            que.pop();
            for(auto dir : dirs){
                int xx = x + dir.first, yy = y + dir.second;
                if(xx < 0 || xx >= rooms.size() || yy < 0 || yy >= rooms[0].size() || rooms[xx][yy] < rooms[x][y] + 1) continue;
                rooms[xx][yy] = rooms[x][y] + 1;
                que.push({xx, yy});
            }
        }
    }



   void wallsAndGates(vector<vector<int>>& rooms) {
        
        if (rooms.empty() || rooms[0].empty()) return;
        
        for (int i = 0; i < rooms.size(); i++)
        {
            for (int j = 0; j < rooms[0].size(); j++)
            {
                if (rooms[i][j] == 0)
                {
                    _dfs(rooms, i, j, 0);
                }
            }
        }
    }
    
/* DFS, TLE */    
    void _dfs(vector<vector<int>>& rooms, int row, int col, int d)
    {
        if (row < 0 || row >= rooms.size() || col < 0 || col >= rooms[0].size() || rooms[row][col] < d)
        {
            return;
        }
        
        rooms[row][col] = d;
        
        _dfs(rooms, row-1, col, d+1);
        _dfs(rooms, row+1, col, d+1);
        _dfs(rooms, row, col-1, d+1);
        _dfs(rooms, row, col-1, d+1);
    }


/* run time error */

    void wallsAndGates(vector<vector<int>>& rooms) {
        
        if (rooms.empty() || rooms[0].empty()) return;
        
        int m = rooms.size(), n = rooms[0].size();
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rooms[i][j] == 0 || rooms[i][j] == -1) continue;
                
                vector<vector<bool>>avail(m, vector<bool>(n, true));
                int d = INT_MAX;
                
                _dfs(rooms, avail, i, j, 0, d);
                
                rooms[i][j] = d;
            }
        }
    }
    
    
    void _dfs(vector<vector<int>> &rooms, vector<vector<bool>>&avail, int row, int col, int dis, int &d)
    {
        if (!avail[row][col] || row < 0 || row >= rooms.size() || col < 0 || col >= rooms[0].size() || rooms[row][col] == -1)
        {
            return;
        }
        
        if (rooms[row][col] == 0) 
        {
            d = min(d, dis);
        }
        
        avail[row][col] = false;
        
        _dfs(rooms, avail, row+1, col, dis+1, d);
        _dfs(rooms, avail, row-1, col, dis+1, d);
        _dfs(rooms, avail, row, col+1, dis+1, d);
        _dfs(rooms, avail, row, col-1, dis+1, d);
        
        avail[row][col] = true;
    }

/*
bluepp
2016-06-15
May the force be with me!

https://leetcode.com/problems/shortest-distance-from-all-buildings/

You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
*/


/* 2017-01-18, update */

    int shortestDistance(vector<vector<int>>& grid) {
        
        int res = INT_MAX, val = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> sum = grid;
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (grid[i][j] == 1) 
                {
                    res = INT_MAX;
                    vector<vector<int>> dist = grid;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    
                    while (!q.empty()) 
                    {
                        int ii = q.front().first, jj = q.front().second;
                        q.pop();
                        
                        for (int k = 0; k < 4; ++k) 
                        {
                            int x = ii + dirs[k][0], y = jj + dirs[k][1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == val) 
                            {
                                grid[x][y]--;
                                
                                dist[x][y] = dist[ii][jj] + 1;
                                sum[x][y] += dist[x][y] - 1;
                                
                                res = min(res, sum[x][y]);
                                
                                q.push({x, y});
                            }
                        }
                    }
                    
                    val--;                    
                }
            }
        }
        
        return res == INT_MAX ? -1 : res;
    }


/* https://leetcode.com/discuss/74453/36-ms-c-solution */
/* https://leetcode.com/discuss/75038/16ms-c-fastest-improvement-of-stefanporsches-code */

    int shortestDistance(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size(), mark = 0, ans;
        vector<vector<int>> dist(m, vector<int>(n, 0));
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    vector<pair<int, int> > bfs(1, make_pair(i, j)), bfs2;
                    
                    int level = 1;
                    ans = INT_MAX;
                    
                    while (!bfs.empty())
                    {
                        for (auto p : bfs)
                        {
                            int x = p.first, y = p.second;
                            
                            for (int d = 0; d < 4; d++)
                            {
                                int nx = x + dx[d], ny = y + dy[d];
                                
                                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == mark)
                                {
                                    grid[nx][ny] = mark-1;
                                    dist[nx][ny] += level;
                                    ans = min(ans, dist[nx][ny]);
                                    bfs2.push_back(make_pair(nx, ny));
                                }
                            }
                        }
                        
                        level++;
                        swap(bfs, bfs2);
                        bfs2.clear();
                    }
                    
                    mark -= 1;
                }
            }
        }
        
        return ans==INT_MAX ? -1 : ans;
    }

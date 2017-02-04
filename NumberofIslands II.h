/*
bluepp
2017-02-04
May the force be with me!

https://leetcode.com/problems/number-of-islands-ii/

A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]
*/

/* union find */
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        
        vector<int> res;
        if (m <= 0 || n <= 0) return res;
        
        vector<int> roots(m*n, -1);
        int count = 0;
        vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        
        for (auto p : positions)
        {
            int id = n * p.first + p.second;
            roots[id] = id;
            count ++;
            
            for (auto d : dirs)
            {
                int x = p.first + d[0], y = p.second + d[1];
                int curr_id = x*n + y;
                
                if (x < 0 || x >= m || y < 0 || y >= n || roots[curr_id] == -1) continue;
                
                int newid = findroots(roots, curr_id);
                
                if (id != newid)
                {
                    roots[id] = newid;
                    id = newid;
                    count--;
                }
            }
            
            res.push_back(count);
        }
        
        return res;
    }
    
    
    int findroots(vector<int> &roots, int id)
    {
        while (id != roots[id])
        {
            roots[id] = roots[roots[id]];
            id = roots[id];
        }
        
        return id;
    }

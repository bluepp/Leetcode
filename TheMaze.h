/*
bluepp
2017-02-20
May the force be with me!

https://leetcode.com/problems/the-maze/?tab=Description

There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

Example 1

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

Example 2

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: false
Explanation: There is no way for the ball to stop at the destination.

*/


/* 1. bfs */
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        if (maze.empty() || maze[0].empty()) return false;
        int m = maze.size(), n = maze[0].size(); 
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;
        
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            
            if (t.first == destination[0] && t.second == destination[1])
            {
                return true;
            }
            
            for (auto d : dirs)
            {
                int x = t.first+d[0], y = t.second+d[1];
                
                while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0)
                {
                    x += d[0];
                    y += d[1];
                }
                
                x -= d[0];
                y -= d[1];
                
                if (!visited[x][y])
                {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        
        return false;
    }

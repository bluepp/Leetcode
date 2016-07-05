/*
2016-06-15
bluepp
May the force be with me!

https://leetcode.com/problems/number-of-islands/

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

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
*/


/*sum up,  https://leetcode.com/discuss/89303/solutions-iterative-version-recursive-version-implementation */

/* 1. dfs */
/* 2. bfs
https://leetcode.com/discuss/86977/bfs-commented-java-solution
*/
/* 3. union find*/

/* 1. dfs */
/* 2016-07-06, update */
    int numIslands(vector<vector<char>>& grid) {
        
        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }
        
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                
                if (grid[i][j] == '1')
                {
                    count++;
                    _dfs(grid, i, j);
                }
            }
        }
        
        return count;
    }
    
    void _dfs(vector<vector<char>> &grid, int row, int col)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1')
        {
            return;
        }
        
        grid[row][col] = 'x';
        
        _dfs(grid, row+1, col);
        _dfs(grid, row-1, col);
        _dfs(grid, row, col+1);
        _dfs(grid, row, col-1);
        
    }

/* 2. bfs */
/* https://leetcode.com/discuss/86977/bfs-commented-java-solution */
public int numIslands(char[][] grid) {
    if(grid.length==0||grid[0].length==0)
        return 0;

    List<List<Point>> islands= new ArrayList<List<Point>>();
    int m=grid.length,n=grid[0].length;
    boolean[][] inSomeIsland= new boolean[m][n];
    int[][] direction = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
    for(int i=0;i<m;i++){
        for(int j=0; j<n;j++){
            if(grid[i][j]=='1'&&!inSomeIsland[i][j]){
                Queue<Point> queue = new LinkedList<>();
                List<Point> island= new ArrayList<Point>();
                queue.add(new Point(i, j));
                inSomeIsland[i][j]=true;
                island.add(new Point(i,j));
                while (!queue.isEmpty()) {
                    Point point = queue.poll();
                    for (int k = 0; k < 4; k++) {
                        int x = direction[k][0] + point.x;
                        int y = direction[k][1] + point.y;
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1'&&!inSomeIsland[x][y]) {
                            island.add(new Point(x,y));
                            inSomeIsland[x][y]=true;
                            queue.add(new Point(x, y));
                        }
                    }
                }
                if(island.size()>0)
                    islands.add(island);    
            }    
        }
    }

    return islands.size(); 

    }




/*
On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

What is the largest possible number of moves we can make?

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Example 3:

Input: stones = [[0,0]]
Output: 0
 

Note:

1 <= stones.length <= 1000
0 <= stones[i][j] < 10000
*/


/* runtime error */

    int removeStones(vector<vector<int>>& stones) {
        
        int m = stones.size(), n = stones[0].size();
        int ret = 0;
        
        for (int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                
                int count = 0;
            
                if (stones[i][j] == 1){
                    _delete(stones, i, j, visited, count);
                }
                
                ret = max(ret, count);
            }
        }
        
        return ret;
    }
    
    void _delete (vector<vector<int>> &stones, int i, int j, vector<vector<bool>> &visited, int &count){
        
        int m = stones.size(), n = stones[0].size();
        
        for (int r = 0; r < m; r++){
            for (int c = 0; c < n; c++){
                
                if ((r != i && c == j && !visited[i][j] && stones[r][c] == 1) ||
                    (c != j && r == i && !visited[i][j] && stones[r][c] == 1)) {
                    count++;
                    visited[i][j] = true;
                }
                
                if (stones[r][c] == 1 && !visited[r][c]){
                    _delete(stones, r, c, visited, count);
                }
            }
        }
        

    }
    

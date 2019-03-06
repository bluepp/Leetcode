/*
Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.
Example:
Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3
Hint: The number of elements in the given matrix will not exceed 10,000.
*/

    int longestLine(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) {
            return 0;
        }
        
        int m = M.size(), n = M[0].size();
        int ret = 0;
        
        vector<vector<int>> dirs {{1, 0}, {0, 1}, {-1, -1}, {-1, 1}};
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 0) {
                    continue;
                }
                
                for (int k = 0; k < 4; k++) {
                    
                    int count = 0;
                    int x = i, y = j;
                    
                    while (x >= 0 && x < m && y >= 0 && y < n && M[x][y] == 1) {
                        x += dirs[k][0];
                        y += dirs[k][1];
                        
                        count++;
                    }
                    
                    ret = max(ret, count);
                    
                }
            }
        }

        return ret;
    }



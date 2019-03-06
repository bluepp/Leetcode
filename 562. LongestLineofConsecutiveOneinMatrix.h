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



/* stack overflow !!! */
    int longestLine(vector<vector<int>>& M) {
        
        int m = M.size(), n = M[0].size();
        int ret = 0;
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                
                int count = 1;
                if (M[i][j] == 1) {
                    _dfs(M, i, j, count);
                }
                
                ret = max(ret, count);
            }
        }
        
        return ret;
    }
    
    void _dfs(vector<vector<int>> &M, int i, int j, int count){
        int m = M.size(), n = M[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || M[i][j] != 1) {  
            return;
        }
                
        _dfs(M, i+1, j, ++count);
        _dfs(M, i-1, j, ++count);
        _dfs(M, i, j+1, ++count);
        _dfs(M, i, j-1, ++count);  
    }

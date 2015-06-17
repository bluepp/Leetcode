/*
  2015-06-18
  bluepp
  May the force be with me!
  
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.

https://leetcode.com/problems/maximal-square/
*/

    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > mat(m, vector<int> (n, 0));
       
        
        for (int i = 0; i < m; i++)
        {
            mat[i][0] = matrix[i][0] == '1' ? 1 : 0;
        }
        
        for (int j = 0; j < n; j++)
        {
            mat[0][j] = matrix[0][j] == '1' ? 1 : 0;
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    mat[i][j] = min(mat[i-1][j-1], min(mat[i-1][j], mat[i][j-1])) + 1;
                }
                else
                {
                    mat[i][j] = 0;
                }
            }
        }
        
        int maxv = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                maxv = max(maxv, mat[i][j]);
            }
        }
        
        return maxv*maxv;
    }

/*
    bluepp
    2014-06-23
    May the force be with me!
    
    
 Problem:    Set Matrix Zeroes
 Source:     https://oj.leetcode.com/problems/set-matrix-zeroes/
 Notes:
 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 Follow up:
 Did you use extra space?
 A straight forward solution using O(mn) space is probably a bad idea.
 A simple improvement uses O(m + n) space, but still not the best solution.
 Could you devise a constant space solution?

 Solution: Use first row and column as auxiliary spaces instead of newly allocating ones.
*/

/* WRONG?! */

void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
            
        int m = matrix.size(), n = matrix[0].size();
        bool firstrow = false, firstcol = false;
        
        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                firstrow = true;
                break;
            }
        }
        
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                break;
                firstcol = true;
            }
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][i] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for (int i = 1; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 1; j < n; j++)
                    matrix[i][j] = 0;
            }
        }
        
        for (int j = 1; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                for (int i = 1; i < m; i++)
                    matrix[i][j] = 0;
            }
        }
        
        if (firstrow)
        {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
        if (firstcol)
        {
            for (int i = 1; i < m; i++)
                matrix[i][0] = 0;
        }
    
    }

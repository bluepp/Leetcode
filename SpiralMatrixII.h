/*
    bluepp
    2014-06-26
    2014-07-27
    2014-08-20
    May the froce be with me!
    
 Problem:    Spiral Matrix II
 Source:     https://oj.leetcode.com/problems/spiral-matrix-ii/
 Notes:
 Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 For example,
 Given n = 3,
 You should return the following matrix:
 [
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 ]

 Solution: ...
 */
 
    vector<vector<int> > generateMatrix(int n) {
        
        if (n == 0) return vector<vector<int> >();
        
        vector<vector<int> > mat(n, vector<int>(n));
        
        int imin = 0, imax = n-1;
        int jmin = 0, jmax = n-1;
        int count = 1;
        
        while (true)
        {
            for (int j = jmin; j <= jmax; j++)
            {
                mat[imin][j] = count++;
            }
            if (++imin > imax) break;
            
            for (int i = imin; i <= imax; i++)
            {
                mat[i][jmax] = count ++;
            }
            if (--jmax < jmin) break;
            
            for (int j = jmax; j >= jmin; j--)
            {
                mat[imax][j] = count++;
            }
            if (--imax < imin) break;
            
            for (int i = imax; i >= imin; i--)
            {
                mat[i][jmin] = count ++;
            }
            if (++jmin > jmax) break;
            
        }
        
        return mat;
       
    }

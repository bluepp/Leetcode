/*
    bluepp
    2014-06-25
    2014-07-27
    2014-08-20
    May the force be with me!
    
 Problem:    Spiral Matrix
 Source:     https://oj.leetcode.com/problems/spiral-matrix/
 Notes:
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 For example,
 Given the following matrix:
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 You should return [1,2,3,6,9,8,7,4,5].

 Solution: ...
 */
 
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
       vector<int> res;
       if (matrix.empty() || matrix[0].empty()) return res;
       
       int m = matrix.size(), n = matrix[0].size();
       
       int imin = 0, imax = m-1;
       int jmin = 0, jmax = n-1;
       
       while (true)
       {
           for (int j = jmin; j <= jmax; j++)
           {
               res.push_back(matrix[imin][j]);
           }
           if (++imin > imax) break;
           
           for (int i = imin; i <= imax; i++)
           {
               res.push_back(matrix[i][jmax]);
           }
           if (jmin > --jmax) break;
           
           for (int j = jmax; j >= jmin; j--)
           {
               res.push_back(matrix[imax][j]);
           }
           if (imin > --imax) break;
           
           for (int i = imax ; i >= imin; i--)
           {
               res.push_back(matrix[i][jmin]);
           }
           
           if (++jmin > jmax) break;
       
       }
       
       return res;
    }
  

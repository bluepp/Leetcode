/*
    bluepp
    2014-06-22
    2014-07-23
    May the force be with me!
    
    Problem:    Rotate Image
 Source:     https://oj.leetcode.com/problems/rotate-image/
 Notes:
 You are given an n x n 2D matrix representing an image.
 Rotate the image by 90 degrees (clockwise).
 Follow up:
 Could you do this in-place?

 Solution: 1. Rotate one-fourth of the image clockwise.
           2. 123   ->  147   ->   741    (preferable)
              456       258        852
              789       369        963
 */
 
 
  void rotate(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
            
        int m = matrix.size(), n = matrix[0].size();
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m/2; j++)
            {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n-1-i; j++)
            {
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
            }
        }
        
        
    }

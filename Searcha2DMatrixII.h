/*
  2015-07-27
  bluepp
  May the force be with me!
  
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

https://leetcode.com/problems/search-a-2d-matrix-ii/
*/

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        
        int i = 0, j = n-1;
        while (i < m && j >= 0)
        {
            if (matrix[i][j] < target)
            {
                i++;
            }
            else if (matrix[i][j] > target)
            {
                j--;
            }
            else 
            {
                return true;
            }
        }
        
        return false;
    }




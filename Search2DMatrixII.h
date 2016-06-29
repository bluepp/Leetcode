/*
bluepp
2016-06-30
May the force be with me!

https://leetcode.com/problems/search-a-2d-matrix-ii/

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
*/

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        
        int x = m-1, y = 0;
        
        while (true)
        {
            if (matrix[x][y] > target)
            {
                x--;
            }
            else if (matrix[x][y] < target)
            {
                y++;
            }
            else 
            {
                return true;
            }
            
            if (x < 0 || y > matrix[0].size()) break;
            
        }
        
        return false;
    }

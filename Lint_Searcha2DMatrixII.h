/*
  2015-09-07
  bluepp
  May the force be with me!
  
  Medium Search a 2D Matrix II Show result 

Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.
This matrix has the following properties:
    * Integers in each row are sorted from left to right.
    * Integers in each column are sorted from up to bottom.
    * No duplicate integers in each row or column.

Have you met this question in a real interview? Yes
Example
Consider the following matrix:

[

    [1, 3, 5, 7],

    [2, 4, 7, 8],

    [3, 5, 9, 10]

]

Given target = 3, return 2.

Challenge
O(m+n) time and O(1) extra space
http://www.lintcode.com/en/problem/search-a-2d-matrix-ii/#
*/

    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        
        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return 0;
        
        int i = 0, j = n-1;
        int ret = 0;
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
                ret ++;
                i++;
            }
        }
        
        return ret;
    }

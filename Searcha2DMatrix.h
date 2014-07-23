/*
    bluepp
    2014-06-22
    2014-07-24
    May the force be with me!
    
 Problem:    Search a 2D Matrix
 Source:     https://oj.leetcode.com/problems/search-a-2d-matrix/
 Notes:
 Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.
 For example,

 Consider the following matrix:

 [
    [1,   3,  5,  7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
 ]
 Given target = 3, return true.

 Solution: Binary-search.
 */
    
    
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        
        while (l <= r)
        {
            int mid = (l+r)/2;
            int row = mid / n, col = mid % n;
            
            if (matrix[row][col] == target)
                return true;
            if (matrix[row][col] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }

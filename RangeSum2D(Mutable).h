/*
bluepp
2016-06-02
May the force be with me!

https://leetcode.com/problems/range-sum-query-2d-mutable/

Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10

*/

/* 2017-02-04, update */

class NumMatrix {
private:
    vector<vector<int>> mat;
    vector<vector<int>> colSum;
    
public:
    NumMatrix(vector<vector<int>> matrix) {
        
        if (matrix.empty() || matrix[0].empty()) return;
        mat = matrix;
        colSum.resize(matrix.size() + 1, vector<int>(matrix[0].size(), 0));
        
        for (int i = 1; i < colSum.size(); ++i) {
            for (int j = 0; j < colSum[0].size(); ++j) {
                colSum[i][j] = colSum[i - 1][j] + matrix[i - 1][j];
            }
        }
    }
    
    void update(int row, int col, int val) {
        
        for (int i = row + 1; i < colSum.size(); ++i) {
            colSum[i][col] += val - mat[row][col];
        }
        
        mat[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int res = 0;
        for (int j = col1; j <= col2; ++j) {
            res += colSum[row2 + 1][j] - colSum[row1][j];
        } 
        
        return res;
    }
};

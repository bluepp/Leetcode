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

class NumMatrix {
private:
    vector<vector<int> > mat;
    
public:
    NumMatrix(vector<vector<int>> &matrix) {
        
        for (int i = 0; i < matrix.size(); i++)
        {
            int sum = 0;
            vector<int> sum_row;
            for (int j = 0; j < matrix[0].size(); j++)
            {
                sum += matrix[i][j];
                sum_row.push_back(sum);
            }
            
            mat.push_back(sum_row);
        }
    }

    void update(int row, int col, int val) {
        
        int delta = mat[row][col-1] + val - mat[row][col];
        
        for (int j = col; j < mat[0].size(); j++)
        {
            mat[row][j] += delta;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        
        for (int i = row1; i <= row2; i++)
        {
            sum += mat[i][col2] - mat[i][col1-1];
        }
        
        return sum;
    }
};

/*
  2015-09-22
  bluepp
  May the force be with me!
  
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in ZigZag-order.

Have you met this question in a real interview? Yes
Example
Given a matrix:

[
  [1, 2,  3,  4],
  [5, 6,  7,  8],
  [9,10, 11, 12]
]
return [1, 2, 5, 9, 6, 3, 4, 7, 10, 11, 8, 12]

http://www.lintcode.com/en/problem/matrix-zigzag-traversal/#
*/
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        vector<int> zigzag;
        const int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m + n - 1; ++i) {
            if (i % 2) {
                for (int y = min(i, n - 1);  y >= max(0, i - m + 1); --y) {
                    zigzag.push_back(matrix[i - y][y]);
                }
            } else {
                for (int x = min(i, m - 1);  x >= max(0, i - n + 1); --x) {
                    zigzag.push_back(matrix[x][i - x]);
                }
            }
        }

        return zigzag;
    }

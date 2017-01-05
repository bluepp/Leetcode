/*
bluepp
2017-01-06
May the force be with me!

https://leetcode.com/problems/max-sum-of-sub-matrix-no-larger-than-k/

Given a non-empty 2D matrix matrix and an integer k, 
find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2
The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?
*/

   int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
        int sum[m][n];
        
        for (int i = 0; i < m; ++i) {
            
            for (int j = 0; j < n; ++j) {
                
                int t = matrix[i][j];
                if (i > 0) t += sum[i - 1][j];
                if (j > 0) t += sum[i][j - 1];
                if (i > 0 && j > 0) t -= sum[i - 1][j - 1];
                
                sum[i][j] = t;
                
                for (int r = 0; r <= i; ++r) {
                    
                    for (int c = 0; c <= j; ++c) {
                        
                        int d = sum[i][j];
                        if (r > 0) d -= sum[r - 1][j];
                        if (c > 0) d -= sum[i][c - 1];
                        if (r > 0 && c > 0) d += sum[r - 1][c - 1];
                        if (d <= k) res = max(res, d);
                    }
                }
            }
        }
        
        return res;
        
    }

/* 
2016-08-31
bluepp
May the force be with me!

https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.
*/

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<int, vector<int>> q;
        
        int m = matrix.size(), n = matrix[0].size();
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                q.push(matrix[i][j]);
                if (q.size() > k)
                {
                    q.pop();
                }
            }
        }
        
        return q.top();
    }

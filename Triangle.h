/*
    bluepp
    
    2014-06-30
    2014-08-01
    2014-08-18
    2014-09-24
    
    May the force be with me!
    
   
 Problem:    Triangle
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/triangle/
 Notes:
 Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 For example, given the following triangle
 [
    [2],
   [3,4],
  [6,5,7],
 [4,1,8,3]
 ]
 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 Note:
 Bonus point if you are able to do this using only O(n) extra space, where n is the total number 
 of rows in the triangle.

 Solution: Note that there are n elements in the n-th row (n starts from 1).
           1. DFS. (Time Limit Exceeded for large test data).
           2. DP. Do not need additional spaces (happen in-place).
           3. DP. O(n) space (If the input 'triangle' can not be changed).
 */
 
 
 
 /* 2 */
    int minimumTotal(vector<vector<int> > &triangle) {
        
       for (int i = triangle.size() - 2; i >= 0; --i)
            for (int j = 0; j < i + 1; ++j)
                triangle[i][j] = triangle[i][j] + min(triangle[i+1][j], triangle[i+1][j+1]);
        return triangle[0][0];
    }

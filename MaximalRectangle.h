/* 
    bluepp  
    2014-06-13
    May the force be with me!
    
    Problem:    Maximal Rectangle
    Source:     https://oj.leetcode.com/problems/maximal-rectangle/
    Notes:
    Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

    Solution: 1. dp. (72 milli secs for the large).
              a) dp[i][j] records the number of consecutive '1' on the left and up of the element matrix[i][j].
              b) For each element(i,j), calculate the area of rectangle including the element itself.
              2. calculate 'Largest Rectangle in Histogram' for each row.
 */
 
 /* The second one */
 
 int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m+1, 0);
        int res = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                height[j] = (matrix[i][j] == '0')? 0:height[j] + 1;
            }
            
            res = max(res, _largeArea(height));
        }
        
        return res;
    }
    
    int _largeArea(const vector<int> &height)
    {
        stack<int> s;
        int res = 0, n = height.size();
        
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            while (!s.empty() && s.top() > height[i])
            {
                count++;
                res = max(res, count*s.top());
                s.pop();
            }
            
            while (count --)
            {
                s.push(height[i]);
            }
            
            s.push(height[i]);
        }
        
        return res;
    }

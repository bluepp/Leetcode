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

/* 2017-02-09, update */
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if (matrix.empty() || matrix[0].empty()) return 0;
        int ret = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n+1, 0);
        
        for (int i = 0; i < m; i++)
        {
            stack<int> s;
            
            for (int j = 0; j < n+1; j++)
            {
                if (j < n)
                {
                    height[j] = matrix[i][j] == '1' ? height[j]+1 : 0;
                }
                
                while (!s.empty() && height[s.top()] >= height[j])
                {
                    int curr = s.top();
                    s.pop();
                    
                    ret = max(ret, height[curr] * (s.empty() ? j : j-s.top()-1));
                }
                
                s.push(j);
            }
        }
        
        return ret;
       
    }
 

/* 2017-01-19, update */

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n+1, 0);
        int ret = 0;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                height[j] = (matrix[i][j] == '0') ? 0 : 1+height[j];
            }
            
            ret = max(ret, _large(height));
        }
        
        return ret;
    }
    
    int _large(const vector<int> &height)
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

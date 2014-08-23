/*
    bluepp
    2014-06-18
    2014-07-19
    2014-08-23
    May the force be with me!
    
    
    Problem:    Pascal's Triangle
    Source:     https://oj.leetcode.com/problems/pascals-triangle/
    Notes:
    Given numRows, generate the first numRows of Pascal's triangle.
    For example, given numRows = 5,
    Return
    [
      [1],
     [1,1],
    [1,2,1],
   [1,3,3,1],
  [1,4,6,4,1]
    ]

    Solution: .....
 */
 
 
    vector<vector<int> > generate(int numRows) {
        
        vector<vector<int> > res(numRows);
        
        for (int i = 0; i < numRows; i++)
        {
            res[i].push_back(1);
            
            for (int j = 1; j < i; j++)
            {
                res[i].push_back(res[i-1][j-1] + res[i-1][j]);
            }
            
            if (i >=1)
                res[i].push_back(1);
            
        }
        
        return res;
        
    }

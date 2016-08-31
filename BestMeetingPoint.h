/*
bluepp
2016-06-02
May the force be with me!


https://leetcode.com/problems/best-meeting-point/

A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.
*/

/* 2016-09-01, update */
    int minTotalDistance(vector<vector<int>>& grid) {
        
        vector<int> row, col;
        
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        
        sort(row.begin(), row.end());
        sort(col.begin(), col.end());
        
        int ret = 0;
        int mid1 = row[row.size()/2], mid2 = col[col.size()/2];
        
        for (auto p : row)
        {
            ret += abs(p-mid1);
        }
        
        for (auto p : col)
        {
            ret += abs(p-mid2);
        }
        
        return ret;
    }
    
    




    int minTotalDistance(vector<vector<int>>& grid) {
        const int row = grid.size();
    
        if (0 == row) return 0;
        const int col = grid[0].size();
        int total = 0;
        vector<int> posR, posC;
        
        for (int i = 0; i < row; ++i) 
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    posR.push_back(i);
                    posC.push_back(j);
                }
        }
        
        int med1 = posR[posR.size() / 2];
//        nth_element(posC.begin(), posC.begin() +  posC.size() / 2, posC.end());
        
        sort(posC.begin(), posC.end());
        int med2 = posC[posC.size() / 2];
        for (auto pos1 : posR) total += abs(pos1 - med1);
        for (auto pos2 : posC) total += abs(pos2 - med2);
        return total;
    }

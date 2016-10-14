/*
bluepp
2016-06-03
May the force be with me!

An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. 
The black pixels are connected, i.e., there is only one black region. 
Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels,
return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

For example, given the following image:

[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2,
Return 6.
*/

/* 1. brute froce, 2. binary search */

/* my solution */
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.empty() || image[0].empty()) return 0;
        
        int m = image.size(), n = image[0].size();
        vector<int> row_vec, col_vec;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (image[i][j] == '1')
                {
                    row_vec.push_back(i);
                    col_vec.push_back(j);
                }
            }
        }
        
        sort(row_vec.begin(), row_vec.end());
        sort(col_vec.begin(), col_vec.end());
        
        int h = row_vec.back() - row_vec.front() +1;
        int w = col_vec.back() - col_vec.front() +1;
        int t = col_vec.front();
        
        return h*w;
    }


/* 2016-10-15, update */

    int minArea(vector<vector<char>>& image, int x, int y) {
        
        int left = y, right = y, up = x, down = x;
        
        dfs(image, x, y, left, right, up, down);
        
        return (right-left+1) *(down-up+1);
    }
    
    void dfs(vector<vector<char>> &image, int x, int y, int &left, int &right, int &up, int &down) {
        
        if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != '1') return;
        left = min(left, y); 
        right = max(right, y);
        up = min(up, x);
        down = max(down, x);
        image[x][y] = 'x';
        dfs(image, x + 1, y, left, right, up, down);
        dfs(image, x - 1, y, left, right, up, down);
        dfs(image, x, y + 1, left, right, up, down);
        dfs(image, x, y - 1, left, right, up, down);
    }



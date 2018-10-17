/*
We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.

 

Example 1:

Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
*/    int matrixScore(vector<vector<int>>& A) {
        
        if(A.empty()) return 0;

        // 首列置为 1
        for(size_t i = 0; i < A.size(); ++i)
        {
            if(A[i][0] == 0)
            {
                FlipRow(A, i);
            }
        }

        // 每列 1 的个数大于 0 的个数
        for(size_t i = 0; i < A[0].size(); ++i)
        {
            if(CntColOne(A, i)*2 < A.size())
            {
                FlipColumn(A, i);
            }
        }

        // 计算二进制值得和
        int ans = 0;
        for(size_t i = 0; i < A.size(); ++i)
        {
            ans += NumRow(A, i);
        }

        return ans;

    }
    
    
    void FlipColumn(vector<vector<int>>& A, int col)
    {
        for(size_t i = 0; i < A.size(); ++i)
        {
            A[i][col] = !A[i][col];
        }
    }

    void FlipRow(vector<vector<int>>& A, int row)
    {
        for(size_t i = 0; i < A[row].size(); ++i)
        {
            A[row][i] = !A[row][i];
        }
    }

   
    int CntColOne(vector<vector<int>>& A, int col)
    {
        int cnt = 0;
        for(size_t i = 0; i < A.size(); ++i)
        {
            cnt += A[i][col];
        }

        return cnt;
    }
    
    int NumRow(vector<vector<int>>& A, int row)
    {
        int ans = 0;
        for(int x : A[row]) ans = (ans << 1)+x;
        return ans;
    }

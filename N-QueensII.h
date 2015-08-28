/*
  2015-08-28
  bluepp
  May the force be with me!
  
Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.

https://leetcode.com/problems/n-queens-ii/
*/

/* bit */
    int totalNQueens(int n) {
       int res = 0;
       
       _sol (n, 0, 0, 0, res);
        return res;
    }
    
    void _sol(int n, int row, int ld, int rd, int &res)
    {
        if (row == (1 << n) - 1)
        {
            res++;
            return;
        }
        int avail = ~(row | ld | rd);
        for (int i = 0; i < n; i++)
        {
            int pos = 1 << i;
            if (avail & pos)
                _sol(n, row | pos, (ld | pos) << 1, (rd | pos) >> 1, res);
        }
    }

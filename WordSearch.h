/*
    bluepp
    
    2014-07-02
    2014-07-28
    2014-08-16
    2014-12-08
    
    May the force be with me!
    
 Problem:    Word Search
 Source:     https://oj.leetcode.com/problems/word-search/
 Notes:
 Given a 2D board and a word, find if the word exists in the grid.
 The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are 
 those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 For example,
 Given board =
 [
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
 ]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.

 Solution: DFS. (For 'visited', using two-dimensional array will be faster than vector<vector>.[90+ms->50+ms])
 */
 
 /* 2014-12-08 */
 /* 2015-09-14, update */
    bool exist(vector<vector<char>>& board, string word) {
       
        if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        
        vector<vector<bool > > avail(m, vector<bool>(n, true));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (_exist(board, word, 0, i, j, avail)) return true;
            }
        }
        
        return false;
    }
    
    bool _exist(vector<vector<char> >&board, string word, int len, int row, int col, vector<vector<bool> >&avail)
    {
        int m = board.size(), n = board[0].size();
        if (len == word.size()) return true;
        
        if (row < 0 || row >= m || col < 0 || col >= n) return false;
        if (board[row][col] != word[len] || !avail[row][col]) return false;
        
        avail[row][col] = false;
        if (_exist(board, word, len+1, row+1, col, avail)) return true;
        if (_exist(board, word, len+1, row-1, col, avail)) return true;
        if (_exist(board, word, len+1, row, col+1, avail)) return true;
        if (_exist(board, word, len+1, row, col-1, avail)) return true;
        avail[row][col] = true;
        
        return false;
    }
    
/* ------------------------------------------------------    */
 
 
 
 
 
 typedef vector<vector<char> > VECTOR2D;
    
    bool exist(VECTOR2D &board, string word) {
        int N = board.size(), M = board[0].size();
        VECTOR2D avail(N, vector<char>(M, 'o'));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (existRe(board, word, 0, i, j, avail))
                    return true;
        return false;
    }

    bool existRe(const VECTOR2D &board, const string &word, int deep, int i, int j, VECTOR2D &avail)
    {
        int N = board.size(), M = board[0].size();
        if (deep == word.size()) return true;
        if (i < 0 || i >= N || j < 0 || j >= M) return false;
        if (board[i][j] != word[deep] || avail[i][j] == 'x') return false;
        
        avail[i][j] = 'x';
        if (existRe(board, word, deep + 1, i-1, j, avail)) return true;
        if (existRe(board, word, deep + 1, i+1, j, avail)) return true;
        if (existRe(board, word, deep + 1, i, j-1, avail)) return true;
        if (existRe(board, word, deep + 1, i, j+1, avail)) return true;
        avail[i][j] = 'o';
        
        return false;
    }
    
    
        bool exist(vector<vector<char> > &board, string word) {
        if (board.empty() || board[0].empty()) return false;
        
        int m = board.size(), n = board[0].size();
        vector<vector<char> > avail(m, vector<char>(n, '0'));
        string s;
        bool existt = false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                _exist(board, word, s, i, j, avail, existt);
            }
        }
        
        return existt;
    }
    
    
    /* my version, TLE */
    void _exist(vector<vector<char> >&board, string word, string &s, int row, int col, vector<vector<char> >&avail, bool &existt)
    {
        if (s == word) {existt = true; return;}
        if (row >= board.size() || col >= board[0].size()) return;
        if (s.size() == word.size()) return;
        
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (avail[i][j] == '0')
                {
                    avail[i][j] = '1';
                    s.push_back(board[i][j]);
                    _exist(board, word, s, row+1, col+1, avail, existt);
                    _exist(board, word, s, row-1, col-1, avail, existt);
                    _exist(board, word, s, row+1, col-1, avail, existt);
                    _exist(board, word, s, row-1, col+1, avail, existt);
                    s.pop_back();
                    avail[i][j] = '0';
                    
                }
            }
        }
    }

/*
  2015-06-15
  bluepp
  May the force be with me!
  
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].

https://leetcode.com/problems/word-search-ii/
*/

/* TLE */
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        
        if (board.empty() || board[0].empty()) return res;
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > avail(m, vector<bool>(n, true));
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                _dfs(board, i, j, avail, "", words, res);
            }
        }
        
        return res;
    }
    
    void _dfs(vector<vector<char> > board, int row, int col, vector<vector<bool> > avail,
            string vec, vector<string> & words, vector<string> &res)
    {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return;
        if (!avail[row][col]) return;
        
        if (find(words, vec))
        {
            res.push_back(vec);
            return;
        }
        
        avail[row][col] = false;
        vec.push_back(board[row][col]);
        
        _dfs(board, row+1, col, avail, vec, words, res);
        _dfs(board, row-1, col, avail, vec, words, res);
        _dfs(board, row, col+1, avail, vec, words, res);
        _dfs(board, row, col-1, avail, vec, words, res);
        
        vec.pop_back();
        avail[row][col] = true;
    }
    
    bool find(vector<string> &words, string vec)
    {
        int n = words.size();
        
        for (int i = 0; i < n; i++)
        {
            if (vec == words[i]) return true;
        }
        
        return false;
    }

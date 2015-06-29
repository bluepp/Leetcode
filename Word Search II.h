/*
  2015-06-29
  bluepp
  May the force be with me!
  
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.

*/

/* 1. barktrack, not trie */
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.empty() || board[0].empty()) return res;
        
        int m = board.size(), n = board[0].size();
        unordered_map<char, unordered_set<char> > neigh;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i-1 >= 0) neigh[board[i][j]].insert(board[i-1][j]);
                if (i+1 < m)  neigh[board[i][j]].insert(board[i+1][j]);
                if (j-1 >= 0) neigh[board[i][j]].insert(board[i][j-1]);
                if (j+1 < n)  neigh[board[i][j]].insert(board[i][j+1]);
            }
        }
        
        unordered_set<string> no_dup(begin(words), end(words));
        for (auto &word : no_dup)
        {
            bool possible = true;
            
            for (int i = 1; possible && i < word.size(); i++)
            {
                possible = neigh[word[i-1]].count(word[i]);
            }
            
            for (int i = 0; possible && i < m; i++)
            {
                for (int j = 0; possible && j < n; j++)
                {
                    if (back(board, word, 0, i, j))
                    {
                        res.push_back(word);
                        possible = false;
                    }
                }
            }
        }
        
        return res;
    }
    
    
    bool back(vector<vector<char> > &board, const string &s, int offset, int i, int j)
    {
        if (offset >= s.length()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != s[offset]) return false;
        
        char c = '.';
        swap(board[i][j], c);
        
        bool found = false;
        if (!found) found = back(board, s, offset+1, i-1, j);
        if (!found) found = back(board, s, offset+1, i+1, j);
        if (!found) found = back(board, s, offset+1, i, j-1);
        if (!found) found = back(board, s, offset+1, i, j+1);
        
        swap(board[i][j], c);
        
        return found;
    }

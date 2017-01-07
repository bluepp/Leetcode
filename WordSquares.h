/*
bluepp
2017-01-07
May the force be with me!

https://leetcode.com/problems/word-squares/

Given a set of words (without duplicates), find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y
Note:
There are at least 1 and at most 1000 words.
All words will have the exact same length.
Word length is at least 1 and at most 5.
Each word contains only lowercase English alphabet a-z.
Example 1:

Input:
["area","lead","wall","lady","ball"]

Output:
[
  [ "wall",
    "area",
    "lead",
    "lady"
  ],
  [ "ball",
    "area",
    "lead",
    "lady"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
Example 2:

Input:
["abat","baba","atan","atal"]

Output:
[
  [ "baba",
    "abat",
    "baba",
    "atan"
  ],
  [ "baba",
    "abat",
    "baba",
    "atal"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
Show Company Tags
Show Tags
Show Similar Problems

*/
   vector<vector<string>> wordSquares(vector<string>& words) {
        
        vector<vector<string>> res;
        unordered_map<string, set<string>> map;
        int n = words[0].length();
        
        for (auto p : words)
        {
            for (int i = 0; i < n; i++)
            {
                string key = p.substr(0, i);
                map[key].insert(p);
            }
        }
        
        vector<vector<char>> mat(n, vector<char>(n));
        
        helper(0, n, mat, map, res);
        return res;
    }
    
    void helper(int i, int n, vector<vector<char>>& mat, unordered_map<string, set<string>>& m, vector<vector<string>>& res) {
        if (i == n) 
        {
                vector<string> out;
                for (int j = 0; j < n; ++j) out.push_back(string(mat[j].begin(), mat[j].end()));
                res.push_back(out);
                return;
        }
        
        string key = string(mat[i].begin(), mat[i].begin() + i);
        
        for (string str : m[key]) 
        {
            mat[i][i] = str[i];
            int j = i + 1;
            for (; j < n; ++j) {
                mat[i][j] = str[j];
                mat[j][i] = str[j];
                if (!m.count(string(mat[j].begin(), mat[j].begin() + i + 1))) break;
            }
            if (j == n) helper(i + 1, n, mat, m, res);
        }
    }

